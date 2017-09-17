#include "stdafx.h"
#include "ManagerView.h"

using std::get;

ManagerView::ManagerView(QWidget *parent)
	: QDialog(parent),
	pManager(dynamic_cast<Manager*>(MainLogic::GetInstance()->pUser)),
	lstService{ "上菜","加水","打包","催单" } 
{
	ui.setupUi(this);
	mdlCook = new QStandardItemModel(this);
	mdlWaiter = new QStandardItemModel(this);
	mdlComm = new QStandardItemModel(this);
	ui.lblInfo->setText("欢迎！尊敬的经理" + str2qstr(pManager->GetName()) + "！");
	QStringList lstCooks, lstWaiters;
	for (auto &c : MainLogic::s_currentCooks)
	{
		lstCooks.push_back(str2qstr(c.first));
	}
	for (auto &w : MainLogic::s_currentWaiters)
	{
		lstWaiters.push_back(str2qstr(w.first));
	}
	ui.cbCook->addItems(lstCooks);
	ui.cbWaiter->addItems(lstWaiters);
	ui.cbCook->setCurrentIndex(0);
	ui.cbWaiter->setCurrentIndex(0);
	PrepareCook();
	PrepareWaiter();
	PrepareVolume();
}

ManagerView::~ManagerView()
{
	pManager = nullptr;
	MainLogic::GetInstance()->pUser = nullptr;
}

void ManagerView::PrepareCook()
{
	if (!idCook.empty())
	{
		ui.tbCook->reset();
		mdlCook->clear();
		mdlCook->setColumnCount(2);
		mdlCook->setHeaderData(0, Qt::Horizontal, "菜品名");
		mdlCook->setHeaderData(1, Qt::Horizontal, "完成量");
		auto res = pManager->CheckCook(MainLogic::s_currentCooks[idCook]);
		auto &done = get<1>(res);
		int nRow = 0;
		for (auto &dish : done)
		{
			mdlCook->setItem(nRow, 0, new QStandardItem(str2qstr(dish.first.GetName())));
			mdlCook->setItem(nRow, 1, new QStandardItem(QString::number(dish.second)));
			++nRow;
		}
		ui.tbCook->setModel(mdlCook);
	}
}

void ManagerView::PrepareWaiter()
{
	if (!idWaiter.empty())
	{
		ui.tbWaiter->reset();
		mdlWaiter->clear();
		mdlWaiter->setColumnCount(2);
		mdlWaiter->setHeaderData(0, Qt::Horizontal, "服务名");
		mdlWaiter->setHeaderData(1, Qt::Horizontal, "完成量");
		auto res = pManager->CheckWaiter(MainLogic::s_currentWaiters[idWaiter]);
		auto &done = get<1>(res);
		int nRow = 0;
		for (auto &serv : done)
		{
			mdlWaiter->setItem(nRow, 0, new QStandardItem(lstService[nRow]));
			mdlWaiter->setItem(nRow, 1, new QStandardItem(QString::number(serv)));
			++nRow;
		}
		ui.tbWaiter->setModel(mdlWaiter);
		auto idComms = get<0>(res);
		ui.tbComm->reset();
		mdlComm->clear();
		mdlComm->setColumnCount(3);
		mdlComm->setHeaderData(0, Qt::Horizontal, "标题");
		mdlComm->setHeaderData(1, Qt::Horizontal, "星级");
		mdlComm->setHeaderData(2, Qt::Horizontal, "内容");
		int nRowC = 0;
		for (auto id : idComms)
		{
			auto &myComment = MainLogic::s_currentComments[id];
			mdlComm->setItem(nRowC, 0, new QStandardItem(str2qstr(myComment.GetName())));
			mdlComm->setItem(nRowC, 1, new QStandardItem(QString::number(myComment.m_nStar)));
			mdlComm->setItem(nRowC, 2, new QStandardItem(str2qstr(myComment.m_strContent)));
			++nRowC;
		}
		ui.tbComm->setModel(mdlComm);
	}
}

bool ManagerView::IsAllVacance()
{
	for (auto &t : MainLogic::GetInstance()->arrSeatVacance)
	{
		if (t == 0)
		{
			return false;
		}
	}
	return true;
}

void ManagerView::PrepareVolume()
{
	ui.tbVolume->setColumnCount(2);
	ui.tbVolume->setHorizontalHeaderItem(0, new QTableWidgetItem("菜品名"));
	ui.tbVolume->setHorizontalHeaderItem(1, new QTableWidgetItem("销量"));
	int nRow = 0;
	for (auto &cu : MainLogic::s_currentMenu)
	{
		ui.tbVolume->setRowCount(1 + nRow);
		ui.tbVolume->setItem(nRow, 0, new QTableWidgetItem(str2qstr(cu.second.GetName())));
		int nVol = 0;
		for (auto &ord : MainLogic::s_currentOrders)
		{
			auto &&mp = ord.second.GetFoodMap();
			auto it = mp.find(cu.first);
			if (it != mp.end())
			{
				nVol += it->second;
			}
		}
		ui.tbVolume->setItem(nRow, 1, new QTableWidgetItem(QString::number(nVol)));
		++nRow;
	}
}

void ManagerView::BindCook(QString qstrCook)
{
	idCook = qstr2str(qstrCook);
	PrepareCook();
}

void ManagerView::BindWaiter(QString qstrWaiter)
{
	idWaiter = qstr2str(qstrWaiter);
	PrepareWaiter();
}

void ManagerView::OnProfile()
{
	ProfileView profile(this);
	profile.exec();
	ui.lblInfo->setText("欢迎！尊敬的经理" + str2qstr(pManager->GetName()) + "！");
}

void ManagerView::OnSetTable()
{
	if (IsAllVacance())
	{
		auto now = MainLogic::GetInstance()->arrSeatVacance.size();
		auto capa = static_cast<size_t>(QInputDialog::getInt(this, "设置", "请设置餐桌总数：", static_cast<int>(now), 1, 36));
		if (capa != now)
		{
			MainLogic::GetInstance()->arrSeatVacance = vector<char>(capa, 1);
		}
	}
	else
	{
		QMessageBox::information(this, "提示", "仍有顾客在用餐，无法设置！");
	}
}
