#include "stdafx.h"
#include "ProjectFrontend.h"

ProjectFrontend::ProjectFrontend(QWidget *parent)
	: QMainWindow(parent)
{
	//UI Init
	ui.setupUi(this);
	MainLogic::GetInstance()->Initialise();
	MainLogic::GetInstance()->arrSeatVacance = vector<char>(100,1);
	pPreload = nullptr;
	bPhone = false;
	bPW = false;
	ui.btnSignIn->setDisabled(true);
}

void ProjectFrontend::OnRegClicked()
{
	RegisterForm subReg(this);
	subReg.exec();
}

ProjectFrontend::~ProjectFrontend()
{
	MainLogic::GetInstance()->Finalise();
	MainLogic::DestroyInstance();
}

void ProjectFrontend::OnLogClicked()
{
	//Proceed the sign-in result
	if (pPreload == nullptr)
	{
		QMessageBox::critical(this, "登录失败","用户不存在！");
		return;
	}
	else if (qstr2str(ui.lePW->text()) != pPreload->GetPassword())
	{
		QMessageBox::critical(this, "登录失败", "密码错误！");
		return;
	}
	MainLogic::GetInstance()->pUser = pPreload;
	//Windows preparations
	QDialog *pView = nullptr;
	//Choose the correct window
	switch (pPreload->GetId()[0])
	{
	case '7':	//Maintainer
		pView = new MaintainerView(this);
		break;
	case '3':	//Customer
		pView = new CustomerView(this);
		break;
	case '5':	//Waitor
		pView = new WaitorView(this);
		break;
	case '4':	//Cook
		pView = new CookView(this);
		break;
	case '6':	//Manager
		pView = new ManagerView(this);
	}
	if (pView != nullptr)
	{
		pView->exec();
		pView->deleteLater();
	}
}

void ProjectFrontend::CheckPhone(QString qstrPhone)
{
	//Do some check on phone edit
	bPhone = true;
	int nLen = qstrPhone.size();
	if (nLen < 11)
	{
		bPhone = false;
	}
	else
	{
		//Prepare the person when phone is ready
		pPreload = MainLogic::GetInstance()->FindExist(qstr2str(qstrPhone));
	}
}

void ProjectFrontend::CheckPW(QString qstrPW)
{
	//Do some check on password edit
	bPW = true;
	int nLen = qstrPW.size();
	if (nLen < 8)
	{
		bPW = false;
	}
}

void ProjectFrontend::paintEvent(QPaintEvent * event)
{
	CheckPhone(ui.lePhone->text());
	CheckPW(ui.lePW->text());
	//Check the sign-in button
	if (bPW && bPhone)
	{
		ui.btnSignIn->setDisabled(false);
	}
	else
	{
		ui.btnSignIn->setDisabled(true);
	}
	QMainWindow::paintEvent(event);
}

void ProjectFrontend::closeEvent(QCloseEvent * event)
{
	auto ret = QMessageBox::question(this, "关闭提示", "您真的要退出系统吗，未完成的订单将直接失效！", QMessageBox::Yes | QMessageBox::No);
	if (ret == QMessageBox::Yes)
	{
		QMainWindow::closeEvent(event);
	}
	else
	{
		event->ignore();
	}
}
