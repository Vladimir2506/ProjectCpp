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
	mdlWaitor = new QStandardItemModel(this);
	mdlComm = new QStandardItemModel(this);
	ui.lblInfo->setText("欢迎！尊敬的经理" + str2qstr(pManager->GetName()));
	QStringList lstCooks, lstWaitors;
	for (auto &c : MainLogic::s_currentCooks)
	{
		lstCooks.push_back(str2qstr(c.first));
	}
	for (auto &w : MainLogic::s_currentWaitors)
	{
		lstWaitors.push_back(str2qstr(w.first));
	}
	ui.cbCook->addItems(lstCooks);
	ui.cbWaitor->addItems(lstWaitors);
	ui.cbCook->setCurrentIndex(0);
	ui.cbWaitor->setCurrentIndex(0);
	PrepareCook();
	PrepareWaitor();
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

void ManagerView::PrepareWaitor()
{
	if (!idWaitor.empty())
	{
		ui.tbWaitor->reset();
		mdlWaitor->clear();
		mdlWaitor->setColumnCount(2);
		mdlWaitor->setHeaderData(0, Qt::Horizontal, "服务名");
		mdlWaitor->setHeaderData(1, Qt::Horizontal, "完成量");
		auto res = pManager->CheckWaitor(MainLogic::s_currentWaitors[idWaitor]);
		auto &done = get<1>(res);
		int nRow = 0;
		for (auto &serv : done)
		{
			mdlWaitor->setItem(nRow, 0, new QStandardItem(lstService[nRow]));
			mdlWaitor->setItem(nRow, 1, new QStandardItem(QString::number(serv)));
			++nRow;
		}
		ui.tbWaitor->setModel(mdlWaitor);
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

void ManagerView::BindCook(QString qstrCook)
{
	idCook = qstr2str(qstrCook);
	PrepareCook();
}

void ManagerView::BindWaitor(QString qstrWaitor)
{
	idWaitor = qstr2str(qstrWaitor);
	PrepareWaitor();
}

void ManagerView::OnProfile()
{
	ProfileView profile(this);
	profile.exec();
	ui.lblInfo->setText("欢迎！尊敬的经理" + str2qstr(pManager->GetName()));
}

void ManagerView::OnSetTable()
{
	if (IsAllVacance())
	{
		auto now = MainLogic::GetInstance()->arrSeatVacance.size();
		auto capa = QInputDialog::getInt(this, "设置", "请设置餐桌总数：", now, 1, 100);
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
