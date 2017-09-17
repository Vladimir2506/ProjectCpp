#include "stdafx.h"
#include "RegisterForm.h"

RegisterForm::RegisterForm(QWidget *parent)
	: QDialog(parent),
	lstCharaters{ "顾客","系统管理员","厨师","服务员","餐厅经理" }	//Dynamic items
{
	//UI Init
	ui.setupUi(this);
	//Pixmap Init
	pixWrong.load("wrong.png");
	pixRight.load("right.png");
	//Buttons Init
	ui.btnSubmit->setDisabled(true);
	ui.btnSubmit->clearFocus();
	ui.cbChar->addItems(lstCharaters);
	ui.cbChar->setCurrentIndex(0);
	nSelect = 0;
	//Flags Init
	bDelta = false;
}

RegisterForm::~RegisterForm()
{

}


void RegisterForm::BindSelect(int nSel)
{
	nSelect = nSel;	// Get current index
}

void RegisterForm::SubmitReg()
{
	//Sign up to a data list
	People *pSignup = nullptr;
	size_t nRecorder = 0;
	string strId;
	string strPhone = qstr2str(ui.lePhone->text());
	string strPassword = qstr2str(ui.lePW->text());
	string strName = qstr2str(ui.leName->text());
	switch (nSelect)
	{
	case CharSel::CH_CUSTOMER:
		if (!MainLogic::s_currentCustomers.empty())
		{
			nRecorder = stoi(MainLogic::s_currentCustomers.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_CUSTOMER, nRecorder);
		pSignup = new Customer(strId, strName, strPassword, strPhone);
		MainLogic::s_currentCustomers.emplace(pSignup->GetId(), *dynamic_cast<Customer*>(pSignup));
		break;
	case CharSel::CH_COOK:
		if (!MainLogic::s_currentCooks.empty())
		{
			nRecorder = stoi(MainLogic::s_currentCooks.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_COOK, nRecorder);
		pSignup = new Cook(strId, strName, strPassword, strPhone);
		MainLogic::s_currentCooks.emplace(pSignup->GetId(), *dynamic_cast<Cook*>(pSignup));
		break;
	case CharSel::CH_WAITOR:
		if (!MainLogic::s_currentWaiters.empty())
		{
			nRecorder = stoi(MainLogic::s_currentWaiters.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_WAITOR, nRecorder);
		pSignup = new Waiter(strId, strName, strPassword, strPhone);
		MainLogic::s_currentWaiters.emplace(pSignup->GetId(), *dynamic_cast<Waiter*>(pSignup));
		break;
	case CharSel::CH_MANAGER:
		if (!MainLogic::s_currentManagers.empty())
		{
			nRecorder = stoi(MainLogic::s_currentManagers.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_MANAGER, nRecorder);
		pSignup = new Manager(strId, strName, strPassword, strPhone);
		MainLogic::s_currentManagers.emplace(pSignup->GetId(), *dynamic_cast<Manager*>(pSignup));
		break;
	case CharSel::CH_MAINTAINER:
		if (!MainLogic::s_currentMaintainers.empty())
		{
			nRecorder = stoi(MainLogic::s_currentMaintainers.rbegin()->first.substr(1, string::npos));
		}
		strId = IdGenerator(IDGENERATOR::ID_MAINTAINER, nRecorder);
		pSignup = new Maintainer(strId, strName, strPassword, strPhone);
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
	bDelta = false;
	accept();
}

void RegisterForm::paintEvent(QPaintEvent * event)
{
	if (bDelta)
	{
		ui.btnSubmit->setDisabled(!(CheckPhone() && CheckPW() && CheckDeux() && CheckName()));
	}
	else
	{
		ui.btnSubmit->setDisabled(true);
	}
	QDialog::paintEvent(event);
}

bool RegisterForm::CheckPW()
{
	auto strPW = ui.lePW->text();
	if (strPW.size() < 8)
	{
		ui.lblState2->setPixmap(pixNil);
		ui.lblErrMsg->setText("");
		return false;
	}
	else
	{
		for (auto &c : strPW)
		{
			if (!c.isDigit() && !c.isLetter())
			{
				ui.lblState2->setPixmap(pixWrong);
				ui.lblErrMsg->setText("密码必须由数字和字母组成！");
				return false;
			}
		}
		ui.lblState2->setPixmap(pixRight);
		return true;
	}
}

bool RegisterForm::CheckPhone()
{
	auto strPhone = ui.lePhone->text();
	if (strPhone.size() < 11)
	{
		ui.lblState1->setPixmap(pixNil);
		ui.lblErrMsg->setText("");
		return false;
	}
	else
	{
		if (MainLogic::GetInstance()->FindExist(qstr2str(strPhone)) != nullptr)
		{
			ui.lblState1->setPixmap(pixWrong);
			ui.lblErrMsg->setText("该手机号已被注册！");
			return false;
		}
		for (auto &c : strPhone)
		{
			if (!c.isDigit())
			{
				ui.lblState1->setPixmap(pixWrong);
				ui.lblErrMsg->setText("请输入正确的手机号码！");
				return false;
			}
		}
		ui.lblState1->setPixmap(pixRight);
		return true;
	}
}

bool RegisterForm::CheckDeux()
{
	auto strPW = ui.lePW->text();
	auto strDeux = ui.lePWDeux->text();
	if (strDeux.size() < 8)
	{
		ui.lblState3->setPixmap(pixNil);
		ui.lblErrMsg->setText("");
		return false;
	}
	else
	{
		if (strDeux != strPW)
		{
			ui.lblState3->setPixmap(pixWrong);
			ui.lblErrMsg->setText("两次输入的密码不一致！");
			return false;
		}
		ui.lblState3->setPixmap(pixRight);
		return true;
	}
}

bool RegisterForm::CheckName()
{
	auto strName = ui.leName->text();
	if (strName.isEmpty())
	{
		ui.lblState4->setPixmap(pixNil);
		ui.lblErrMsg->setText("");
		return false;
	}
	else
	{
		ui.lblState4->setPixmap(pixRight);
		return true;
	}
}

void RegisterForm::OnDelta()
{
	bDelta = true;
	CheckDeux();
	CheckName();
	CheckPW();
	CheckPhone();
}
