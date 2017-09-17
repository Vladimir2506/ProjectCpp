#include "stdafx.h"
#include "WaiterView.h"

WaiterView::WaiterView(QWidget *parent)
	: QDialog(parent),
	pWaiter(dynamic_cast<Waiter*>(MainLogic::GetInstance()->pUser)),
	lstService{ "上菜","加水","打包","催单" }
{
	ui.setupUi(this);
	if (pWaiter->IsIdle())
	{
		ui.lblInfo->setText("您好！尊敬的服务员" + str2qstr(pWaiter->GetName()));
	}
	else
	{
		ui.lblInfo->setText("您好！尊敬的服务员" + str2qstr(pWaiter->GetName()) + ",您服务的桌号为" + QString::number(pWaiter->GetTableNum() + 1));
	}
	mdlDone = new QStandardItemModel(this);
	PrepareDemand();
	PrepareDone();
	PreparePlates();
}

WaiterView::~WaiterView()
{
	pWaiter = nullptr;
	MainLogic::GetInstance()->pUser = nullptr;
}

void WaiterView::paintEvent(QPaintEvent * event)
{
	if (pWaiter->IsIdle())
	{
		ui.btnDemand->setDisabled(true);
		ui.btnServe->setDisabled(true);
	}
	else
	{
		ui.btnDemand->setDisabled(itDemand == pWaiter->m_deqTodo.end());
		ui.btnServe->setDisabled(itDish == pWaiter->m_deqReady.end());
	}
	QDialog::paintEvent(event);
}

void WaiterView::OnSelPlate(int nRow)
{
	itDish = pWaiter->m_deqReady.begin() + nRow;
}

void WaiterView::OnDemand()
{
	pWaiter->DoDemand(itDemand);
	PrepareDemand();
	PrepareDone();
}

void WaiterView::OnDeliver()
{
	pWaiter->ServePlate(itDish);
	PreparePlates();
	PrepareDone();
}

void WaiterView::OnProfile()
{
	ProfileView profile(this);
	profile.exec();
	if (pWaiter->IsIdle())
	{
		ui.lblInfo->setText("您好！尊敬的服务员" + str2qstr(pWaiter->GetId()));
	}
	else
	{
		ui.lblInfo->setText("您好！尊敬的服务员" + str2qstr(pWaiter->GetId()) + ",您服务的桌号为" + QString::number(pWaiter->GetTableNum()));
	}
}

void WaiterView::OnSelDemand(int nRow)
{
	itDemand = pWaiter->m_deqTodo.begin() + nRow;
}

void WaiterView::PreparePlates()
{
	ui.lstPlate->clear();
	for (auto &pl : pWaiter->m_deqReady)
	{
		ui.lstPlate->addItem(str2qstr(pl.first.GetName()));
	}
	itDish = pWaiter->m_deqReady.begin();
}

void WaiterView::PrepareDemand()
{
	ui.lstDemand->clear();
	for (auto &dm : pWaiter->m_deqTodo)
	{
		ui.lstDemand->addItem(new QListWidgetItem(lstService[dm]));
	}
	itDemand = pWaiter->m_deqTodo.begin();
}

void WaiterView::PrepareDone()
{
	ui.tbDone->reset();
	mdlDone->clear();
	mdlDone->setColumnCount(2);
	mdlDone->setHeaderData(0, Qt::Horizontal, "服务项目");
	mdlDone->setHeaderData(1, Qt::Horizontal, "已完成量");
	int nRow = 0;
	for (auto & ser : pWaiter->GetServDone())
	{
		mdlDone->setItem(nRow, 0, new QStandardItem(lstService[nRow]));
		mdlDone->setItem(nRow, 1, new QStandardItem(QString::number(ser)));
		++nRow;
	}
	ui.tbDone->setModel(mdlDone);
}
