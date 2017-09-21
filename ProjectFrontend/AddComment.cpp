#include "stdafx.h"
#include "AddComment.h"

AddComment::AddComment(int nIdMode, Customer *p,QWidget *parent)
	: QDialog(parent),
	pCustomer(p)
{
	ui.setupUi(this);
	nMode = nIdMode;
	switch (nIdMode)
	{
	case IDGENERATOR::ID_CUISINE:
		pComm = &p->m_statusComment;
		break;
	case IDGENERATOR::ID_WAITOR:
		ui.btnBack->hide();
		ui.btnNext->hide();
		pComm = &p->m_waiterComment;
		break;
	default:
		pComm = nullptr;
	}
	arrStars = { ui.lbls1,ui.lbls2,ui.lbls3,ui.lbls4,ui.lbls5 };
	pixStarFul.load("Resources/starful.png");
	pixStarNil.load("Resources/starnil.png");
	itThis = pComm->begin();
	itEnd = pComm->end();
	--itEnd;
	PrepareComment();
	bDelta = false;
}

AddComment::~AddComment()
{

}

void AddComment::paintEvent(QPaintEvent * event)
{
	if (bDelta)
	{
		ui.btnBack->setDisabled(true);
		ui.btnNext->setDisabled(true);
		ui.btnCommit->setDisabled(!IsFullAll());
	}
	else
	{
		ui.btnBack->setDisabled(itThis == pComm->begin());
		ui.btnNext->setDisabled(itThis == itEnd);
		ui.btnCommit->setDisabled(true);
	}
	QDialog::paintEvent(event);
}

void AddComment::SetStars(int nStars)
{
	ui.sbStars->setValue(nStars);
	for (int i = 0; i < 5; ++i)
	{
		arrStars[i]->setPixmap(pixStarNil);
		if (i < nStars)
		{
			arrStars[i]->setPixmap(pixStarFul);
		}
	}
}

bool AddComment::IsFullAll()
{
	return !ui.teContent->toPlainText().isEmpty()
		&& !ui.leTitle->text().isEmpty();
}

void AddComment::PrepareComment()
{
	switch (nMode)
	{
	case IDGENERATOR::ID_CUISINE:
		ui.lblName->setText(str2qstr(MainLogic::s_currentMenu[itThis->first].GetName()));
		break;
	case IDGENERATOR::ID_WAITOR:
		ui.lblName->setText(str2qstr(MainLogic::s_currentWaiters[itThis->first].GetName()));
		break;
	default:
		break;
	}
	if (itThis->second == "")
	{
		ui.leTitle->setText("");
		ui.teContent->setText("");
		SetStars(0);
	}
	else
	{
		ui.leTitle->setText(str2qstr(MainLogic::s_currentComments[itThis->second].GetName()));
		ui.teContent->setText(str2qstr(MainLogic::s_currentComments[itThis->second].m_strContent));
		SetStars(MainLogic::s_currentComments[itThis->second].m_nStar);
	}
	bDelta = false;
}

void AddComment::OnDelta()
{
	bDelta = true;
}

void AddComment::OnCommit()
{
	if (itThis->second  == "")
	{
		size_t nRec = 0;
		if (!MainLogic::s_currentComments.empty())
		{
			nRec = stoi(MainLogic::s_currentComments.rbegin()->first.substr(1, string::npos));
		}
		string strId = IdGenerator(ID_COMMENT, nRec);
		string strName = qstr2str(ui.leTitle->text());
		string strDate = qstr2str(QDate::currentDate().toString("yyyy/MM/dd"));
		auto tmp = MainLogic::s_currentComments.emplace(strId, Comment(strId, strName, pCustomer->GetId(),itThis->first, strDate)).first;
		tmp->second.m_nStar = ui.sbStars->value();
		tmp->second.m_strContent = qstr2str(ui.teContent->toPlainText());
		itThis->second = strId;
	}
	else
	{
		auto &cm = MainLogic::s_currentComments[itThis->second];
		cm.SetName(qstr2str(ui.leTitle->text()));
		cm.m_nStar = ui.sbStars->value();
		cm.m_strContent = qstr2str(ui.teContent->toPlainText());
	}
	bDelta = false;
}

void AddComment::BackOne()
{
	if (itThis != pComm->begin())
	{
		--itThis;
	}
	PrepareComment();
}

void AddComment::NextOne()
{
	if (itThis != itEnd)
	{
		++itThis;
	}
	PrepareComment();
}

bool AddComment::IsEmptyAll()
{
	return ui.teContent->toPlainText().isEmpty()
		&& ui.leTitle->text().isEmpty();
}