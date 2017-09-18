#include "stdafx.h"
#include "ProfileView.h"

ProfileView::ProfileView(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	pixRight.load("Resources/right.png");
	pixWrong.load("Resources/wrong.png");
	pMe = MainLogic::GetInstance()->pUser;
	if (pMe->GetId()[0] == '3')
	{
		MyResize(1000, 800);
		mdlComments = new QStandardItemModel(this);
		mdlOrders = new QStandardItemModel(this);
		for (auto &ord : MainLogic::s_currentOrders)
		{
			if (ord.second.GetCustomerId() == pMe->GetId())
			{
				myOrders << str2qstr(ord.first);
			}
		}
		ui.cbOrders->addItems(myOrders);
		ui.cbOrders->setCurrentIndex(0);
		PrepareComments();
	}
	else
	{
		MyResize(500, 525);
		mdlComments = nullptr;
		mdlOrders = nullptr;
	}
	PrepareInfo();
	bDelta = false;
}

ProfileView::~ProfileView()
{

}

void ProfileView::paintEvent(QPaintEvent * event)
{
	if (bDelta)
	{
		ui.btnUndo->setDisabled(false);
		ui.btnSave->setDisabled(!(CheckDeux() && CheckPW() && CheckPhone() && CheckName()));
	}
	else
	{
		ui.btnSave->setDisabled(true);
		ui.btnUndo->setDisabled(true);
	}
}
void ProfileView::OnDelta()
{
	bDelta = true;
}
void ProfileView::OnSave()
{
	pMe->SetPhone(qstr2str(ui.lePhone->text()));
	pMe->SetName(qstr2str(ui.leName->text()));
	pMe->SetPassword(qstr2str(ui.lePassword->text()));
	PrepareInfo();
	bDelta = false;
}

void ProfileView::OnUndo()
{
	PrepareInfo();
	bDelta = false;
}

void ProfileView::BindOrder(QString qstrId)
{
	idOrder = qstr2str(qstrId);
	PrepareOrders(idOrder);
}

void ProfileView::MyResize(int w, int h)
{
	setMaximumSize(w, h);
	setMinimumSize(w, h);
	resize(w, h);
}

bool ProfileView::CheckPW()
{
	auto strPW = ui.lePassword->text();
	if (strPW.size() < 8)
	{
		ui.lblState2->setPixmap(pixNil);
		return false;
	}
	else
	{
		for (auto &c : strPW)
		{
			if (!c.isDigit() && !c.isLetter())
			{
				ui.lblState2->setPixmap(pixWrong);
				return false;
			}
		}
		ui.lblState2->setPixmap(pixRight);
		return true;
	}
}

bool ProfileView::CheckPhone()
{
	auto strPhone = ui.lePhone->text();
	if (strPhone.size() < 11)
	{
		ui.lblState1->setPixmap(pixNil);
		return false;
	}
	else
	{
		auto &&thePerson = MainLogic::GetInstance()->FindExist(qstr2str(strPhone));
		if (thePerson != nullptr && thePerson != pMe)
		{
			ui.lblState1->setPixmap(pixWrong);
			return false;
		}
		for (auto &c : strPhone)
		{
			if (!c.isDigit())
			{
				ui.lblState1->setPixmap(pixWrong);
				return false;
			}
		}
		ui.lblState1->setPixmap(pixRight);
		return true;
	}
}

bool ProfileView::CheckDeux()
{
	auto strPW = ui.lePassword->text();
	auto strDeux = ui.leDeux->text();
	if (strDeux.size() < 8)
	{
		ui.lblState3->setPixmap(pixNil);
		return false;
	}
	else
	{
		if (strDeux != strPW)
		{
			ui.lblState3->setPixmap(pixWrong);
			return false;
		}
		ui.lblState3->setPixmap(pixRight);
		return true;
	}
}

bool ProfileView::CheckName()
{
	auto strName = ui.leName->text();
	if (strName.isEmpty())
	{
		ui.lblState4->setPixmap(pixNil);
		return false;
	}
	else
	{
		ui.lblState4->setPixmap(pixRight);
		return true;
	}
}

void ProfileView::PrepareInfo()
{
	ui.leID->setText(str2qstr(pMe->GetId()));
	ui.leName->setText(str2qstr(pMe->GetName()));
	ui.lePhone->setText(str2qstr(pMe->GetPhone()));
	ui.lePassword->setText(str2qstr(pMe->GetPassword()));
	ui.leDeux->setText("");
}

void ProfileView::PrepareOrders(const string &idOrder)
{
	auto theOrder = MainLogic::s_currentOrders[idOrder];
	ui.tbOrders->reset();
	mdlOrders->clear();
	mdlOrders->setColumnCount(2);
	mdlOrders->setHeaderData(0, Qt::Horizontal, "菜品名");
	mdlOrders->setHeaderData(1, Qt::Horizontal, "数量");
	int nRow = 0;
	for (auto &i : theOrder.GetFoodMap())
	{
		mdlOrders->setItem(nRow, 0, new QStandardItem(str2qstr(i.first.GetName())));
		mdlOrders->setItem(nRow, 1, new QStandardItem(QString::number(i.second)));
		++nRow;
	}
	ui.tbOrders->setModel(mdlOrders);
}

void ProfileView::PrepareComments()
{
	string idCustomer(pMe->GetId());
	for (auto &c : MainLogic::s_currentComments)
	{
		if (c.second.GetUserId() == idCustomer)
		{
			myComments.push_back(c.first);
		}
	}
	ui.tbComments->reset();
	mdlComments->clear();
	mdlComments->setColumnCount(4);
	mdlComments->setHeaderData(0, Qt::Horizontal, "评论标题");
	mdlComments->setHeaderData(1, Qt::Horizontal, "评论星级");
	mdlComments->setHeaderData(2, Qt::Horizontal, "评论内容");
	mdlComments->setHeaderData(3, Qt::Horizontal, "评论日期");
	int nRow = 0;
	for (auto &id : myComments)
	{
		auto theComment = MainLogic::s_currentComments[id];
		mdlComments->setItem(nRow, 0, new QStandardItem(str2qstr(theComment.GetName())));
		mdlComments->setItem(nRow, 1, new QStandardItem(QString::number(theComment.m_nStar)));
		mdlComments->setItem(nRow, 2, new QStandardItem(str2qstr(theComment.m_strContent)));
		mdlComments->setItem(nRow, 3, new QStandardItem(str2qstr(theComment.GetDate())));
		++nRow;
	}
	ui.tbComments->setModel(mdlComments);
}
