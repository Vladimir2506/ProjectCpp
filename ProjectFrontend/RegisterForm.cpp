#include "stdafx.h"
#include "RegisterForm.h"

RegisterForm::RegisterForm(QWidget *parent)
	: QDialog(parent),
	lstCharaters{ "顾客","系统管理员","厨师","服务员","餐厅经理" }	//Dynamic items
{
	//UI Init
	ui.setupUi(this);
	pixWrong.load("wrong.png");
	pixRight.load("right.png");
	ui.btnSubmit->setDisabled(true);
	ui.btnSubmit->clearFocus();
	bPhone = false;
	bPW = false;
	bDeux = false;
	bUnique = false;
	ui.cbChar->addItems(lstCharaters);
	ui.cbChar->setCurrentIndex(0);
	nSelect = 0;
}

RegisterForm::~RegisterForm()
{

}

void RegisterForm::CheckPhone(QString qstrPhone)
{
	//Check phone number is registered
	bUnique = true;
	bPhone = true;
	int nLen = qstrPhone.size();
	if (nLen < 11)
	{
		ui.lblState1->setPixmap(pixNil);
		bPhone = false;
		bUnique = false;
		return;
	}
	else 
	{
		for (auto &qc : qstrPhone)
		{
			if (!qc.isDigit())
			{
				//Check phone number validity
				bPhone = false;
				break;
			}
		}
		bUnique = (MainLogic::GetInstance()->FindExist(qstr2str(qstrPhone)) == nullptr);
	}
	//Set icon
	if (bPhone && bUnique)
	{
		ui.lblState1->setPixmap(pixRight);
	}
	else
	{
		ui.lblState1->setPixmap(pixWrong);
	}
}

void RegisterForm::CheckPW(QString qstrPW)
{
	CheckDeux(ui.lePWDeux->text());		//Check the confirmation immideiately
	bPW = true;
	int nLen = qstrPW.size();
	if (nLen < 8)
	{
		ui.lblState2->setPixmap(pixNil);
		bPW = false;
		return;
	}
	else
	{
		for (auto &qc : qstrPW)
		{
			//Only letters and numbers are permitted
			if (!(qc.isDigit() || qc.isLetter()))
			{
				bPW = false;
				break;
			}
		}
	}
	//Set icon
	if (bPW)
	{
		ui.lblState2->setPixmap(pixRight);
	}
	else
	{
		ui.lblState2->setPixmap(pixWrong);
	}
}

void RegisterForm::CheckDeux(QString qstrDeux)
{
	bDeux = true;
	int nLen = qstrDeux.size();
	if (nLen < 8)
	{
		ui.lblState3->setPixmap(pixNil);
		bDeux = false;
		return;
	}
	if (qstrDeux != ui.lePW->text())
	{
		bDeux = false;
	}
	//Set icon
	if (bDeux)
	{
		ui.lblState3->setPixmap(pixRight);
	}
	else
	{
		ui.lblState3->setPixmap(pixWrong);
	}
}

void RegisterForm::BindSelect(int nSel)
{
	nSelect = nSel;	// get current index
}

void RegisterForm::SubmitReg()
{
	//Sign up to a data list
	People *pSignup = nullptr;
	size_t nRecorder = 0;
	string strId;
	string strName = qstr2str(ui.lePhone->text());
	string strPassword = qstr2str(ui.lePW->text());
	switch (nSelect)
	{
	case CharSel::CH_CUSTOMER:
		if (!MainLogic::s_currentCustomers.empty())
		{
			nRecorder = stoi(MainLogic::s_currentCustomers.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_CUSTOMER, nRecorder);
		pSignup = new Customer(strId, strName, strPassword);
		MainLogic::s_currentCustomers.emplace(pSignup->GetId(), *dynamic_cast<Customer*>(pSignup));
		break;
	case CharSel::CH_COOK:
		if (!MainLogic::s_currentCooks.empty())
		{
			nRecorder = stoi(MainLogic::s_currentCooks.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_COOK, nRecorder);
		pSignup = new Cook(strId, strName, strPassword);
		MainLogic::s_currentCooks.emplace(pSignup->GetId(), *dynamic_cast<Cook*>(pSignup));
		break;
	case CharSel::CH_WAITOR:
		if (!MainLogic::s_currentWaitors.empty())
		{
			nRecorder = stoi(MainLogic::s_currentWaitors.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_WAITOR, nRecorder);
		pSignup = new Waitor(strId, strName, strPassword);
		MainLogic::s_currentWaitors.emplace(pSignup->GetId(), *dynamic_cast<Waitor*>(pSignup));
		break;
	case CharSel::CH_MANAGER:
		if (!MainLogic::s_currentManagers.empty())
		{
			nRecorder = stoi(MainLogic::s_currentManagers.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_MANAGER, nRecorder);
		pSignup = new Manager(strId, strName, strPassword);
		MainLogic::s_currentManagers.emplace(pSignup->GetId(), *dynamic_cast<Manager*>(pSignup));
		break;
	case CharSel::CH_MAINTAINER:
		if (!MainLogic::s_currentMaintainers.empty())
		{
			nRecorder = stoi(MainLogic::s_currentMaintainers.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_MAINTAINER, nRecorder);
		pSignup = new Maintainer(strId, strName, strPassword);
		MainLogic::s_currentMaintainers.emplace(pSignup->GetId(), *dynamic_cast<Maintainer*>(pSignup));
		break;
	default:
		break;
	}
	if (pSignup != nullptr)
	{
		delete pSignup;
		pSignup = nullptr;
	}
	accept();
}

void RegisterForm::paintEvent(QPaintEvent * event)
{
	//Set error information
	if (ui.lePhone->text().size() == 11 && (!bPhone || !bUnique))
	{
		if (!bUnique)
		{
			ui.lblErrMsg->setText("该手机号已被注册！");
		}
		if (!bPhone)
		{
			ui.lblErrMsg->setText("请输入正确的手机号码！");
		}
	}
	else if (ui.lePW->text().size() == 8 && (!bPW))
	{
		ui.lblErrMsg->setText("密码必须由数字和字母组成！");
	}
	else if (ui.lePWDeux->text().size() == 8 && (!bDeux))
	{
		ui.lblErrMsg->setText("两次输入的密码不一致！");
	}
	else
	{
		ui.lblErrMsg->setText("");
	}
	//Check sign-up button
	if (bPW && bPhone && bDeux && bUnique)
	{
		ui.btnSubmit->setDisabled(false);
	}
	else
	{
		ui.btnSubmit->setDisabled(true);
	}
	QDialog::paintEvent(event);
}
