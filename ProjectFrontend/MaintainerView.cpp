#include "stdafx.h"
#include "MaintainerView.h"

MaintainerView::MaintainerView(QWidget *parent)
	: QDialog(parent),
	lstCata{ "顾客","系统管理员","厨师","服务员","餐厅经理" },
	nCata(0)
	,pMaintainer(dynamic_cast<Maintainer*>(MainLogic::GetInstance()->pUser))
{
	ui.setupUi(this);
	//Init data units
	mdlMenu = new QStandardItemModel(this);
	mdlUser = new QStandardItemModel(this);
	//Set welcome
	ui.lblInfo->setText("欢迎！尊敬的" + str2qstr(pMaintainer->GetName()) + "管理员");
	//Load Icons
	pixCom.load("Resources/commit.png");
	pixMod.load("Resources/modify.png");
	//Set data display of menu
	PrepareMenu();
	//Init flags of menu
	bMenuDelta = false;
	bMenuLastEmpty = false;
	bMenuSelect = false;
	nMenuSel = -1;
	connect(ui.tbMenu->model(), SIGNAL(itemChanged(QStandardItem*)), this, SLOT(OnMenuDelta(QStandardItem*)));
	//Set data display of user
	PrepareUser();
	ui.lblCommit->setPixmap(pixCom);
	//Set user catalog combobox
	ui.cbCata->addItems(lstCata);
	ui.cbCata->setCurrentIndex(0);
	connect(ui.tbUser->model(), SIGNAL(itemChanged(QStandardItem*)), this, SLOT(OnUserDelta(QStandardItem*)));
}

MaintainerView::~MaintainerView()
{
	pMaintainer = nullptr;
	MainLogic::GetInstance()->pUser = nullptr;
}

void MaintainerView::OnUserSelected(QModelIndex qInd)
{
	//Check the last row empty
	bUserSelect = true;
	nUserSel = qInd.row();
	auto lastRow = mdlUser->rowCount() - 1;
	auto colCount = mdlUser->columnCount();
	bUserLastEmpty = true;
	for (int i = 0; i < colCount; ++i)
	{
		if (!mdlUser->item(lastRow, i)->text().isEmpty())
		{
			bUserLastEmpty = false;
			break;
		}
	}
	//If the last row is empty without selected
	if (bUserLastEmpty && lastRow != nUserSel)
	{
		mdlUser->removeRow(lastRow);
		bUserLastEmpty = false;
	}
}

void MaintainerView::OnMenuDelta(QStandardItem * pDelta)
{
	bMenuDelta = true;
}

void MaintainerView::OnUserDelta(QStandardItem * pDelta)
{
	bUserDelta = true;
}

void MaintainerView::SaveChangedMenu()
{
	//Resolve all deltas of display and logic
	CheckDataValidity(mdlMenu);
	ui.tbMenu->reset();
	ResolveDeltaMenu();
	PrepareMenu();
	ui.tbMenu->setModel(mdlMenu);
	bMenuDelta = false;
	bMenuSelect = false;
}

void MaintainerView::RecoverMenu()
{
	//Roll back to last logic
	ui.tbMenu->reset();
	PrepareMenu();
	ui.tbMenu->setModel(mdlMenu);
	bMenuDelta = false;
	bMenuSelect = false;
}

void MaintainerView::NewCuisine()
{
	//Add new row in display
	if (!bMenuLastEmpty)
	{
		QList<QStandardItem*> lst{ new QStandardItem(""),new QStandardItem("") ,new QStandardItem(""),new QStandardItem("") };
		mdlMenu->appendRow(lst);
		bMenuLastEmpty = true;
		bMenuDelta = true;
	}
}

void MaintainerView::DelCuisine()
{
	//Delete the selected row in display
	if (bMenuSelect)
	{
		if (nMenuSel == mdlMenu->rowCount() - 1)
		{
			bMenuLastEmpty = false;
		}
		mdlMenu->removeRow(nMenuSel);
		bMenuSelect = false;
		ui.tbMenu->clearSelection();
		bMenuDelta = true;
	}
}

void MaintainerView::NewUser()
{
	if (!bUserLastEmpty)
	{
		QList<QStandardItem*> lst{ new QStandardItem(""),new QStandardItem("") ,new QStandardItem(""),new QStandardItem("") };
		mdlUser->appendRow(lst);
		bUserLastEmpty = true;
		bUserDelta = true;
	}
}

void MaintainerView::SaveChangedUser()
{
	CheckDataValidity(mdlUser);
	ui.tbUser->reset();
	ResolveDeltaUser();
	PrepareUser();
	ui.tbUser->setModel(mdlUser);
	bUserDelta = false;
	bUserSelect = false;
}

void MaintainerView::RecoverUser()
{
	ui.tbUser->reset();
	PrepareUser();
	ui.tbUser->setModel(mdlUser);
	bUserDelta = false;
	bUserSelect = false;
}

void MaintainerView::DelUser()
{
	if (bUserSelect)
	{
		if (nUserSel == mdlUser->rowCount() - 1)
		{
			bUserLastEmpty = false;
		}
		mdlUser->removeRow(nUserSel);
		bUserSelect = false;
		ui.tbUser->clearSelection();
		bUserDelta = true;
	}
}

void MaintainerView::BindCatalogue(int nSel)
{
	nCata = nSel;
	ResetUserButtons();
	ui.tbUser->reset();
	PrepareUser();
	ui.tbUser->setModel(mdlUser);
	bUserDelta = false;
}

void MaintainerView::paintEvent(QPaintEvent * event)
{
	//Menu buttons status
	if (bMenuDelta && !bMenuLastEmpty)
	{
		ui.btnSaveMenu->setDisabled(false);
		ui.btnUndoMenu->setDisabled(false);
	}
	else
	{
		ui.btnSaveMenu->setDisabled(true);
		ui.btnUndoMenu->setDisabled(true);
	}
	if (bMenuLastEmpty)
	{
		ui.btnAddMenu->setDisabled(true);
	}
	else
	{
		ui.btnAddMenu->setDisabled(false);
	}
	if (bMenuSelect)
	{
		ui.btnDelMenu->setDisabled(false);
	}
	else
	{
		ui.btnDelMenu->setDisabled(true);
	}
	//User buttons status
	if (bUserDelta && !bUserLastEmpty)
	{
		//There are some changes
		ui.btnSaveUser->setDisabled(false);
		ui.btnUndoUser->setDisabled(false);
		ui.lblCommit->setPixmap(pixMod);
		ui.cbCata->setDisabled(true);
	}
	else
	{
		//No changes
		ui.btnSaveUser->setDisabled(true);
		ui.btnUndoUser->setDisabled(true);
		ui.lblCommit->setPixmap(pixCom);
		ui.cbCata->setDisabled(false);
	}
	if (bUserLastEmpty)
	{
		ui.btnAddUser->setDisabled(true);
	}
	else
	{
		ui.btnAddUser->setDisabled(false);
	}
	if (bUserSelect)
	{
		ui.btnDelUser->setDisabled(false);
	}
	else
	{
		ui.btnDelUser->setDisabled(true);
	}
	ui.btnComment->setDisabled(bMenuDelta || bUserDelta);
	ui.btnOrder->setDisabled(bMenuDelta || bUserDelta);
	QDialog::paintEvent(event);
}

void MaintainerView::ResolveDeltaMenu()
{
	//For add-values or modifications
	for (int i = 0; i < mdlMenu->rowCount(); ++i)
	{
		string strId(qstr2str(mdlMenu->item(i, 0)->text()));
		string strName(qstr2str(mdlMenu->item(i, 1)->text()));
		double dPrice(mdlMenu->item(i, 2)->text().toDouble());
		int nCate(mdlMenu->item(i, 3)->text().toInt());
		auto it = MainLogic::s_currentMenu.find(strId);
		if (it == MainLogic::s_currentMenu.end())
		{
			MainLogic::s_currentMenu.emplace(strId, Cuisine(strId, strName, dPrice, nCate));
		}
		else
		{
			it->second.SetName(strName);
			it->second.SetPrice(dPrice);
			it->second.SetCate(nCate);
		}
	}
	//For delete-values
	vector<string> idDeleteLaters;
	for (auto &d : MainLogic::s_currentMenu)
	{
		bool bFound = false;
		QString qstrOrigin(str2qstr(d.first));
		for (int i = 0; i < mdlMenu->rowCount(); ++i)
		{
			if (mdlMenu->item(i, 0)->text() == qstrOrigin)
			{
				bFound = true;
				break;
			}
		}
		if (!bFound)
		{
			idDeleteLaters.push_back(d.first);
		}
	}
	//Delete Later
	for (auto &id : idDeleteLaters)
	{
		MainLogic::s_currentMenu[id].DeleteMe(MainLogic::GetInstance()->MainDB);
		MainLogic::s_currentMenu.erase(id);
	}
}

void MaintainerView::ResolveDeltaUser()
{
	switch (nCata)
	{
	case CharSel::CH_CUSTOMER:
		CustomerDelta();
		break;
	case CharSel::CH_WAITOR:
		WaiterDelta();
		break;
	case CharSel::CH_COOK:
		CookDelta();
		break;
	case CharSel::CH_MANAGER:
		ManagerDelta();
		break;
	case CharSel::CH_MAINTAINER:
		MaintainerDelta();
		break;
	default:
		break;
	}
}

void MaintainerView::CustomerDelta()
{
	//Add or adjust values
	for (int i = 0; i < mdlUser->rowCount(); ++i)
	{
		string strId(qstr2str(mdlUser->item(i, 0)->text()));
		string strName(qstr2str(mdlUser->item(i, 1)->text()));
		string strPassword(qstr2str(mdlUser->item(i, 2)->text()));
		string strPhone(qstr2str(mdlUser->item(i, 3)->text()));
		auto it = MainLogic::s_currentCustomers.find(strId);
		if (it == MainLogic::s_currentCustomers.end())
		{
			MainLogic::s_currentCustomers.emplace(strId, Customer(strId, strName, strPassword, strPhone));
		}
		else
		{
			it->second.SetName(strName);
			it->second.SetPassword(strPassword);
			it->second.SetPhone(strPhone);
		}
	}
	//Del values
	vector<string> idDeleteLaters;
	for (auto &d : MainLogic::s_currentCustomers)
	{
		bool bFound = false;
		QString qstrOrigin(str2qstr(d.first));
		for (int i = 0; i < mdlUser->rowCount(); ++i)
		{
			if (mdlUser->item(i, 0)->text() == qstrOrigin)
			{
				bFound = true;
				break;
			}
		}
		if (!bFound)
		{
			idDeleteLaters.push_back(d.first);
		}
	}
	for (auto &id : idDeleteLaters)
	{
		MainLogic::s_currentCustomers[id].DeleteMe(MainLogic::GetInstance()->MainDB);
		MainLogic::s_currentCustomers.erase(id);
	}
}

void MaintainerView::CookDelta()
{
	//Add or adjust values
	for (int i = 0; i < mdlUser->rowCount(); ++i)
	{
		string strId(qstr2str(mdlUser->item(i, 0)->text()));
		string strName(qstr2str(mdlUser->item(i, 1)->text()));
		string strPassword(qstr2str(mdlUser->item(i, 2)->text()));
		string strPhone(qstr2str(mdlUser->item(i, 3)->text()));
		auto it = MainLogic::s_currentCooks.find(strId);
		if (it == MainLogic::s_currentCooks.end())
		{
			MainLogic::s_currentCooks.emplace(strId, Cook(strId, strName, strPassword, strPhone));
		}
		else
		{
			it->second.SetName(strName);
			it->second.SetPassword(strPassword);
			it->second.SetPhone(strPhone);
		}
	}
	//Del values
	vector<string> idDeleteLaters;
	for (auto &d : MainLogic::s_currentCooks)
	{
		bool bFound = false;
		QString qstrOrigin(str2qstr(d.first));
		for (int i = 0; i < mdlUser->rowCount(); ++i)
		{
			if (mdlUser->item(i, 0)->text() == qstrOrigin)
			{
				bFound = true;
				break;
			}
		}
		if (!bFound)
		{
			idDeleteLaters.push_back(d.first);
		}
	}
	for (auto &id : idDeleteLaters)
	{
		MainLogic::s_currentCooks[id].DeleteMe(MainLogic::GetInstance()->MainDB);
		MainLogic::s_currentCooks.erase(id);
	}
}

void MaintainerView::WaiterDelta()
{
	//Add or adjust values
	for (int i = 0; i < mdlUser->rowCount(); ++i)
	{
		string strId(qstr2str(mdlUser->item(i, 0)->text()));
		string strName(qstr2str(mdlUser->item(i, 1)->text()));
		string strPassword(qstr2str(mdlUser->item(i, 2)->text()));
		string strPhone(qstr2str(mdlUser->item(i, 3)->text()));
		auto it = MainLogic::s_currentWaiters.find(strId);
		if (it == MainLogic::s_currentWaiters.end())
		{
			MainLogic::s_currentWaiters.emplace(strId, Waiter(strId, strName, strPassword, strPhone));
		}
		else
		{
			it->second.SetName(strName);
			it->second.SetPassword(strPassword);
			it->second.SetPhone(strPhone);
		}
	}
	//Del values
	vector<string> idDeleteLaters;
	for (auto &d : MainLogic::s_currentWaiters)
	{
		bool bFound = false;
		QString qstrOrigin(str2qstr(d.first));
		for (int i = 0; i < mdlUser->rowCount(); ++i)
		{
			if (mdlUser->item(i, 0)->text() == qstrOrigin)
			{
				bFound = true;
				break;
			}
		}
		if (!bFound)
		{
			idDeleteLaters.push_back(d.first);
		}
	}
	for (auto &id : idDeleteLaters)
	{
		MainLogic::s_currentWaiters[id].DeleteMe(MainLogic::GetInstance()->MainDB);
		MainLogic::s_currentWaiters.erase(id);
	}
}

void MaintainerView::ManagerDelta()
{
	//Add or adjust values
	for (int i = 0; i < mdlUser->rowCount(); ++i)
	{
		string strId(qstr2str(mdlUser->item(i, 0)->text()));
		string strName(qstr2str(mdlUser->item(i, 1)->text()));
		string strPassword(qstr2str(mdlUser->item(i, 2)->text()));
		string strPhone(qstr2str(mdlUser->item(i, 3)->text()));
		auto it = MainLogic::s_currentManagers.find(strId);
		if (it == MainLogic::s_currentManagers.end())
		{
			MainLogic::s_currentManagers.emplace(strId, Manager(strId, strName, strPassword, strPhone));
		}
		else
		{
			it->second.SetName(strName);
			it->second.SetPassword(strPassword);
			it->second.SetPhone(strPhone);
		}
	}
	//Del values
	vector<string> idDeleteLaters;
	for (auto &d : MainLogic::s_currentManagers)
	{
		bool bFound = false;
		QString qstrOrigin(str2qstr(d.first));
		for (int i = 0; i < mdlUser->rowCount(); ++i)
		{
			if (mdlUser->item(i, 0)->text() == qstrOrigin)
			{
				bFound = true;
				break;
			}
		}
		if (!bFound)
		{
			idDeleteLaters.push_back(d.first);
		}
	}
	for (auto &id : idDeleteLaters)
	{
		MainLogic::s_currentManagers[id].DeleteMe(MainLogic::GetInstance()->MainDB);
		MainLogic::s_currentManagers.erase(id);
	}
}

void MaintainerView::MaintainerDelta()
{
	//Add or adjust values
	for (int i = 0; i < mdlUser->rowCount(); ++i)
	{
		string strId(qstr2str(mdlUser->item(i, 0)->text()));
		string strName(qstr2str(mdlUser->item(i, 1)->text()));
		string strPassword(qstr2str(mdlUser->item(i, 2)->text()));
		string strPhone(qstr2str(mdlUser->item(i, 3)->text()));
		auto it = MainLogic::s_currentMaintainers.find(strId);
		if (it == MainLogic::s_currentMaintainers.end())
		{
			MainLogic::s_currentMaintainers.emplace(strId, Maintainer(strId, strName, strPassword, strPhone));
		}
		else
		{
			it->second.SetName(strName);
			it->second.SetPassword(strPassword);
			it->second.SetPhone(strPhone);
		}
	}
	//Del values
	vector<string> idDeleteLaters;
	for (auto &d : MainLogic::s_currentMaintainers)
	{
		bool bFound = false;
		QString qstrOrigin(str2qstr(d.first));
		for (int i = 0; i < mdlUser->rowCount(); ++i)
		{
			if (mdlUser->item(i, 0)->text() == qstrOrigin)
			{
				bFound = true;
				break;
			}
		}
		if (!bFound)
		{
			idDeleteLaters.push_back(d.first);
		}
	}
	for (auto &id : idDeleteLaters)
	{
		MainLogic::s_currentMaintainers[id].DeleteMe(MainLogic::GetInstance()->MainDB);
		MainLogic::s_currentMaintainers.erase(id);
	}
}

void MaintainerView::CustomerPrepare()
{
	int nRow = 0;
	for (auto &d : MainLogic::s_currentCustomers)
	{
		QStandardItem *pId = new QStandardItem(str2qstr(d.first));
		QStandardItem *pName = new QStandardItem(str2qstr(d.second.GetName()));
		QStandardItem *pPassword = new QStandardItem(str2qstr(d.second.GetPassword()));
		QStandardItem *pPhone = new QStandardItem(str2qstr(d.second.GetPhone()));
		mdlUser->setItem(nRow, 0, pId);
		mdlUser->setItem(nRow, 1, pName);
		mdlUser->setItem(nRow, 2, pPassword);
		mdlUser->setItem(nRow, 3, pPhone);
		++nRow;
	}
}

void MaintainerView::CookPrepare()
{
	int nRow = 0;
	for (auto &d : MainLogic::s_currentCooks)
	{
		QStandardItem *pId = new QStandardItem(str2qstr(d.first));
		QStandardItem *pName = new QStandardItem(str2qstr(d.second.GetName()));
		QStandardItem *pPassword = new QStandardItem(str2qstr(d.second.GetPassword()));
		QStandardItem *pPhone = new QStandardItem(str2qstr(d.second.GetPhone()));
		mdlUser->setItem(nRow, 0, pId);
		mdlUser->setItem(nRow, 1, pName);
		mdlUser->setItem(nRow, 2, pPassword);
		mdlUser->setItem(nRow, 3, pPhone);
		++nRow;
	}
}

void MaintainerView::WaiterPrepare()
{
	int nRow = 0;
	for (auto &d : MainLogic::s_currentWaiters)
	{
		QStandardItem *pId = new QStandardItem(str2qstr(d.first));
		QStandardItem *pName = new QStandardItem(str2qstr(d.second.GetName()));
		QStandardItem *pPassword = new QStandardItem(str2qstr(d.second.GetPassword()));
		QStandardItem *pPhone = new QStandardItem(str2qstr(d.second.GetPhone()));
		mdlUser->setItem(nRow, 0, pId);
		mdlUser->setItem(nRow, 1, pName);
		mdlUser->setItem(nRow, 2, pPassword);
		mdlUser->setItem(nRow, 3, pPhone);
		++nRow;
	}
}

void MaintainerView::ManagerPrepare()
{
	int nRow = 0;
	for (auto &d : MainLogic::s_currentManagers)
	{
		QStandardItem *pId = new QStandardItem(str2qstr(d.first));
		QStandardItem *pName = new QStandardItem(str2qstr(d.second.GetName()));
		QStandardItem *pPassword = new QStandardItem(str2qstr(d.second.GetPassword()));
		QStandardItem *pPhone = new QStandardItem(str2qstr(d.second.GetPhone()));
		mdlUser->setItem(nRow, 0, pId);
		mdlUser->setItem(nRow, 1, pName);
		mdlUser->setItem(nRow, 2, pPassword);
		mdlUser->setItem(nRow, 3, pPhone);
		++nRow;
	}
}

void MaintainerView::MaintainerPrepare()
{
	int nRow = 0;
	for (auto &d : MainLogic::s_currentMaintainers)
	{
		QStandardItem *pId = new QStandardItem(str2qstr(d.first));
		QStandardItem *pName = new QStandardItem(str2qstr(d.second.GetName()));
		QStandardItem *pPassword = new QStandardItem(str2qstr(d.second.GetPassword()));
		QStandardItem *pPhone = new QStandardItem(str2qstr(d.second.GetPhone()));
		mdlUser->setItem(nRow, 0, pId);
		mdlUser->setItem(nRow, 1, pName);
		mdlUser->setItem(nRow, 2, pPassword);
		mdlUser->setItem(nRow, 3, pPhone);
		++nRow;
	}
}

void MaintainerView::CheckDataValidity(QStandardItemModel * mdl)
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

void MaintainerView::OnCommentClicked()
{
	CommentSupervise comsu(this);
	comsu.exec();
}

void MaintainerView::OnOrderClicked()
{
	OrderSupervise ordsu(this);
	ordsu.exec();
}

void MaintainerView::ResetUserButtons()
{
	bUserDelta = false;
	bUserLastEmpty = false;
	bUserSelect = false;
	nUserSel = -1;
}

void MaintainerView::PrepareMenu()
{
	//Load menu information from MainLogic
	ui.tbMenu->reset();
	mdlMenu->clear();
	mdlMenu->setColumnCount(4);
	mdlMenu->setHeaderData(0, Qt::Horizontal, "ID");
	mdlMenu->setHeaderData(1, Qt::Horizontal, "名称");
	mdlMenu->setHeaderData(2, Qt::Horizontal, "价格");
	mdlMenu->setHeaderData(3, Qt::Horizontal, "类别");
	int nRow = 0;
	for (auto &d : MainLogic::s_currentMenu)
	{
		QStandardItem *pId = new QStandardItem(str2qstr(d.first));
		QStandardItem *pName = new QStandardItem(str2qstr(d.second.GetName()));
		QStandardItem *pPrice = new QStandardItem(QString::number(d.second.GetPrice()));
		QStandardItem *pCate = new QStandardItem(QString::number(d.second.GetCate()));
		mdlMenu->setItem(nRow, 0, pId);
		mdlMenu->setItem(nRow, 1, pName);
		mdlMenu->setItem(nRow, 2, pPrice);
		mdlMenu->setItem(nRow, 3, pCate);
		++nRow;
	}
	ui.tbMenu->setModel(mdlMenu);
}

void MaintainerView::PrepareUser()
{
	//Load the catalogue of the user
	ui.tbUser->reset();
	mdlUser->clear();
	mdlUser->setColumnCount(4);
	mdlUser->setHeaderData(0, Qt::Horizontal, "ID");
	mdlUser->setHeaderData(1, Qt::Horizontal, "用户名");
	mdlUser->setHeaderData(2, Qt::Horizontal, "密码");
	mdlUser->setHeaderData(3, Qt::Horizontal, "手机号码");
	switch (nCata)
	{
	case CharSel::CH_CUSTOMER:
		CustomerPrepare();
		break;
	case CharSel::CH_COOK:
		CookPrepare();
		break;
	case CharSel::CH_WAITOR:
		WaiterPrepare();
		break;
	case CharSel::CH_MANAGER:
		ManagerPrepare();
		break;
	case CharSel::CH_MAINTAINER:
		MaintainerPrepare();
		break;
	default:
		break;
	}
	ui.tbUser->setModel(mdlUser);
}

void MaintainerView::OnMenuSelected(QModelIndex qInd)
{
	//Check the last row empty
	bMenuSelect = true;
	nMenuSel = qInd.row();
	auto lastRow = mdlMenu->rowCount() - 1;
	auto colCount = mdlMenu->columnCount();
	bMenuLastEmpty = true;
	for (int i = 0; i < colCount; ++i)
	{
		if (!mdlMenu->item(lastRow, i)->text().isEmpty())
		{
			bMenuLastEmpty = false;
			break;
		}
	}
	//If the last row is empty without selected
	if (bMenuLastEmpty && lastRow != nMenuSel)
	{
		mdlMenu->removeRow(lastRow);
		bMenuLastEmpty = false;
	}
}