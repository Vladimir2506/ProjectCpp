#include "stdafx.h"
#include "ProjectFrontend.h"

ProjectFrontend::ProjectFrontend(QWidget *parent)
	: QMainWindow(parent)
{
	//UI Init
	ui.setupUi(this);
	//Data and logic Init
	try
	{
		MainLogic::GetInstance()->Initialise();
	}
	catch (const exception &ex)
	{
		QMessageBox::critical(nullptr, "��⵽�쳣", ex.what());
#ifdef WINVER
		PostQuitMessage(-1);
#endif
	}
	MainLogic::GetInstance()->arrSeatVacance = vector<char>(36, 1);
	//Sign-in Init
	pPreload = nullptr;
	ui.btnSignIn->setDisabled(true);
}

void ProjectFrontend::OnRegClicked()
{
	//Invoke sign-up view
	hide();
	RegisterForm subReg(nullptr);
	subReg.exec();
	show();
}

ProjectFrontend::~ProjectFrontend()
{
	//Data and logic Finale
	try
	{
		MainLogic::GetInstance()->Finalise();
	}
	catch (const exception &ex)
	{
		QMessageBox::critical(nullptr, "��⵽�쳣", ex.what());
#ifdef WINVER
		PostQuitMessage(-1);
#endif
	}
	MainLogic::DestroyInstance();
}

void ProjectFrontend::OnLogClicked()
{
	//Proceed the sign-in result
	if (pPreload == nullptr)
	{
		QMessageBox::critical(this, "��¼ʧ��","�û������ڣ�");
		return;
	}
	else if (qstr2str(ui.lePW->text()) != pPreload->GetPassword())
	{
		QMessageBox::critical(this, "��¼ʧ��", "�������");
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
		pView = new MaintainerView(nullptr);
		break;
	case '3':	//Customer
		pView = new CustomerView(nullptr);
		break;
	case '5':	//Waiter
		pView = new WaiterView(nullptr);
		break;
	case '4':	//Cook
		pView = new CookView(nullptr);
		break;
	case '6':	//Manager
		pView = new ManagerView(nullptr);
	}
	if (pView != nullptr)
	{
		//Load the corresponding view
		hide();
		pView->exec();
		show();
		pView->deleteLater();
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
		"�ر���ʾ", "�����Ҫ�˳�ϵͳ��δ��ɵĶ�����ֱ��ʧЧ��",
		QMessageBox::Yes | QMessageBox::No))
	{
		QMainWindow::closeEvent(event);
	}
	else
	{
		event->ignore();
	}
}
