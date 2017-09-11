#include "stdafx.h"
#include "OrderSupervise.h"

OrderSupervise::OrderSupervise(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	mdlFoodMap = new QStandardItemModel(this);
	itThis = MainLogic::s_currentOrders.begin();
	ui.tbFood->setModel(mdlFoodMap);
	connect(ui.tbFood->model(), SIGNAL(itemChanged(QStandardItem*)), this, SLOT(OnDelta()));
	bDelta = false;
	bLastEmpty = false;
	bSel = false;
	nSel = -1;
	PrepareOrder();
}

OrderSupervise::~OrderSupervise()
{
}

void OrderSupervise::paintEvent(QPaintEvent * event)
{
	if (bDelta)
	{
		ui.btnAdd->setDisabled(true);
		ui.btnNext->setDisabled(true);
		ui.btnBack->setDisabled(true);
		if (IsFullNow() || (IsEmptyAll() && itThis != MainLogic::s_currentOrders.end()))
		{
			ui.btnSave->setDisabled(false);
		}
		else
		{
			ui.btnSave->setDisabled(true);
		}
		ui.btnUndo->setDisabled(false);
	}
	else
	{
		if (IsEmptyAll())
		{
			ui.btnAdd->setDisabled(true);
		}
		else
		{
			ui.btnAdd->setDisabled(false);
		}
		if (itThis != MainLogic::s_currentOrders.end())
		{
			ui.btnNext->setDisabled(false);
		}
		else
		{
			ui.btnNext->setDisabled(true);
		}
		if (itThis != MainLogic::s_currentOrders.begin())
		{
			ui.btnBack->setDisabled(false);
		}
		else
		{
			ui.btnBack->setDisabled(true);
		}
		ui.btnSave->setDisabled(true);
		ui.btnUndo->setDisabled(true);
	}
	ui.btnNLine->setDisabled(bLastEmpty);
	ui.btnDLine->setDisabled(!bSel);
	QDialog::paintEvent(event);
}

void OrderSupervise::NewLine()
{
	QList<QStandardItem*> lst{ new QStandardItem(""),new QStandardItem("") };
	mdlFoodMap->appendRow(lst);
	bLastEmpty = true;
	bDelta = true;
}

void OrderSupervise::DelLine()
{
	if (bSel)
	{
		if (nSel = mdlFoodMap->rowCount() - 1)
		{
			bLastEmpty = false;
		}
		mdlFoodMap->removeRow(nSel);
		ui.tbFood->clearSelection();
		bSel = false;
	}
}

void OrderSupervise::OnSelected(QModelIndex qInd)
{
	//Check the last row empty
	bSel = true;
	nSel = qInd.row();
	auto lastRow = mdlFoodMap->rowCount() - 1;
	bLastEmpty = true;
	for (int i = 0; i < 2; ++i)
	{
		if (!mdlFoodMap->item(lastRow, i)->text().isEmpty())
		{
			bLastEmpty = false;
			break;
		}
	}
	//If the last row is empty without selected
	if (bLastEmpty && lastRow != nSel)
	{
		mdlFoodMap->removeRow(lastRow);
		bLastEmpty = false;
	}
}

void OrderSupervise::NextOne()
{
	if (itThis != MainLogic::s_currentOrders.end())
	{
		++itThis;
	}
	PrepareOrder();
}

void OrderSupervise::BackOne()
{
	if (itThis != MainLogic::s_currentOrders.begin())
	{
		--itThis;
	}
	PrepareOrder();
}

void OrderSupervise::OnSaveClick()
{
	if (IsFullNow())
	{
		CheckDataValidity(mdlFoodMap);
		ResolveDelta();
	}
	if (IsEmptyAll())
	{
		if (itThis == MainLogic::s_currentOrders.end())
		{
			return;
		}
		else
		{
			itThis->second.DeleteMe(MainLogic::GetInstance()->MainDB);
			MainLogic::s_currentOrders.erase(itThis++);
		}
	}
	PrepareOrder();
}

void OrderSupervise::OnUndoClick()
{
	PrepareOrder();
}

void OrderSupervise::OnAddClick()
{
	itThis = MainLogic::s_currentOrders.end();
	PrepareOrder();
}

void OrderSupervise::OnDelClick()
{
	ui.leCustomer->setText("");
	ui.leID->setText("");
	ui.leName->setText("");
	ui.leWaitor->setText("");
	ui.leTableNO->setText("");
	mdlFoodMap->clear();
	bSel = false;
	bDelta = true;
}

void OrderSupervise::PrepareOrder()
{
	ui.tbFood->reset();
	if (itThis != MainLogic::s_currentOrders.end())
	{
		ui.leCustomer->setText(str2qstr(itThis->second.GetCustomerId()));
		ui.leID->setText(str2qstr(itThis->second.GetId()));
		ui.leName->setText(str2qstr(itThis->second.GetName()));
		ui.leWaitor->setText(str2qstr(itThis->second.GetWaitorId()));
		ui.leTableNO->setText(QString::number(itThis->second.GetTableNum()));
	}
	else
	{
		ui.leCustomer->setText("");
		ui.leID->setText("");
		ui.leName->setText("");
		ui.leWaitor->setText("");
		ui.leTableNO->setText("");
		InitModel();
	}
	InitModel();
	ui.tbFood->setModel(mdlFoodMap);
	bDelta = false;
	bSel = false;
}


void OrderSupervise::InitModel()
{
	mdlFoodMap->clear();
	mdlFoodMap->setColumnCount(2);
	mdlFoodMap->setHeaderData(0, Qt::Horizontal, "²ËÆ·ID");
	mdlFoodMap->setHeaderData(1, Qt::Horizontal, "ÊýÁ¿");
	if (itThis != MainLogic::s_currentOrders.end())
	{
		int nRow = 0;
		for (auto &dish : itThis->second.GetFoodMap())
		{
			mdlFoodMap->setItem(nRow, 0, new QStandardItem(str2qstr(dish.first.GetId())));
			mdlFoodMap->setItem(nRow, 1, new QStandardItem(QString::number(dish.second)));
			++nRow;
		}
	}
	bLastEmpty = false;
}

bool OrderSupervise::IsEmptyAll()
{
	return ui.leCustomer->text().isEmpty()
		&& ui.leID->text().isEmpty()
		&& ui.leName->text().isEmpty()
		&& ui.leWaitor->text().isEmpty()
		&& ui.leTableNO->text().isEmpty()
		&& mdlFoodMap->rowCount() == 0;
}

bool OrderSupervise::IsFullNow()
{
	return !ui.leCustomer->text().isEmpty()
		&& !ui.leID->text().isEmpty()
		&& !ui.leName->text().isEmpty()
		&& !ui.leWaitor->text().isEmpty()
		&& !ui.leTableNO->text().isEmpty()
		&& mdlFoodMap->rowCount() != 0;
}

void OrderSupervise::CheckDataValidity(QStandardItemModel * mdl)
{
	vector<int> nDelLaters;
	int nRow = mdl->rowCount();
	int nCol = mdl->columnCount();
	for (int i = 0; i < nRow; ++i)
	{
		bool bInvalid = false;
		for (int j = 0; j < nCol; ++j)
		{
			if (mdl->item(i, j)->text().isEmpty())
			{
				bInvalid = true;
				break;
			}
		}
		if (bInvalid)
		{
			nDelLaters.push_back(i);
		}
	}
	for (auto &r : nDelLaters)
	{
		mdl->removeRow(r);
	}
}

void OrderSupervise::ResolveDelta()
{
	map<Cuisine, int> tmp;
	for (int i = 0; i < mdlFoodMap->rowCount(); ++i)
	{
		Cuisine dish = MainLogic::s_currentMenu[qstr2str(mdlFoodMap->item(i, 0)->text())];
		int num = mdlFoodMap->item(i, 1)->text().toInt();
		tmp.insert(make_pair(dish, num));
	}
	if (itThis == MainLogic::s_currentOrders.end())
	{
		Order oin(qstr2str(ui.leID->text()), qstr2str(ui.leName->text()), qstr2str(ui.leCustomer->text()), qstr2str(ui.leWaitor->text()));
		oin.SetTableNum(ui.leTableNO->text().toInt());
		oin.SetFoodMap(tmp);
		MainLogic::s_currentOrders.insert(make_pair(oin.GetId(), oin));
		itThis = MainLogic::s_currentOrders.find(oin.GetId());
	}
	else
	{
		itThis->second.SetFoodMap(tmp);
		itThis->second.SetId(qstr2str(ui.leID->text()));
		itThis->second.SetName(qstr2str(ui.leName->text()));
		itThis->second.SetCustomerId(qstr2str(ui.leCustomer->text()));
		itThis->second.SetWaitorId(qstr2str(ui.leWaitor->text()));
		itThis->second.SetTableNum(ui.leTableNO->text().toInt());
	}
}

void OrderSupervise::OnDelta()
{
	bDelta = true;
}