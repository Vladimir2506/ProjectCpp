#include "stdafx.h"
#include "ProjectFrontend.h"

ProjectFrontend::ProjectFrontend(QWidget *parent)
	: QMainWindow(parent)
{
	//UI Init
	ui.setupUi(this);
	//Data and logic Init
	MainLogic::GetInstance()->Initialise();
	MainLogic::GetInstance()->arrSeatVacance = vector<char>(36, 1);
	//Sign-in Init
	pPreload = nullptr;
	ui.btnSignIn->setDisabled(true);
}

void ProjectFrontend::OnRegClicked()
{
	//Invoke sign-up view
	RegisterForm subReg(this);
	subReg.exec();
}

ProjectFrontend::~ProjectFrontend()
{
	//Data and logic Finale
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
	//Load the user to Init the user view
	MainLogic::GetInstance()->pUser = pPreload;
	//Windows preparations
	QDialog *pView = nullptr;
	//Choose the correct view
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
		//Load the corresponding view
		pView->exec();
		pView->deleteLater();		//Prevent the data duplication
	}
}

bool ProjectFrontend::CheckPhone()
{
	//Do some check on phone edit
	auto strPhone = ui.lePhone->text();
	if (strPhone.size() < 11)
	{
		return false;
	}
	else
	{
		//Prepare the person when phone is ready
		pPreload = MainLogic::GetInstance()->FindExist(qstr2str(strPhone));
		return true;
	}
}

bool ProjectFrontend::CheckPW()
{
	//Do some check on password edit
	return ui.lePW->text().size() == 8;
}

void ProjectFrontend::paintEvent(QPaintEvent * event)
{
	//Check the sign-in button
	ui.btnSignIn->setDisabled(!(CheckPhone() && CheckPW()));
	QMainWindow::paintEvent(event);
}

void ProjectFrontend::closeEvent(QCloseEvent * event)
{
	//Confirm exit is not an accident
	if (QMessageBox::Yes == QMessageBox::question(this,
		"关闭提示", "您真的要退出系统吗，未完成的订单将直接失效！",
		QMessageBox::Yes | QMessageBox::No))
	{
		QMainWindow::closeEvent(event);
	}
	else
	{
		event->ignore();
	}
}
