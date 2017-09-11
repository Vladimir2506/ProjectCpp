#include "stdafx.h"
#include "BrowseComment.h"

BrowseComment::BrowseComment(const string &strCuisineId, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	pixStarFul.load("starful.png");
	pixStarNil.load("starnil.png");
	for (auto &c : MainLogic::s_currentComments)
	{
		if (c.second.GetDishId() == strCuisineId)
		{
			vecComments.push_back(c.second);
		}
	}
	itThis = vecComments.begin();
	arrStars = { ui.lbls1,ui.lbls2,ui.lbls3,ui.lbls4,ui.lbls5 };
	PrepareComment();
}

BrowseComment::~BrowseComment()
{
}

void BrowseComment::paintEvent(QPaintEvent * event)
{
	ui.btnBack->setDisabled(itThis == vecComments.begin());
	ui.btnNext->setDisabled(itThis == vecComments.end());
	QDialog::paintEvent(event);
}

void BrowseComment::BackOne()
{
	if (itThis != vecComments.begin())
	{
		--itThis;
	}
	PrepareComment();
}

void BrowseComment::NextOne()
{
	if (itThis != vecComments.end())
	{
		++itThis;
	}
	PrepareComment();
}

void BrowseComment::PrepareComment()
{
	if (itThis != vecComments.end())
	{
		ui.teContent->setText(str2qstr(itThis->m_strContent));
		SetStars(itThis->m_nStar);
		ui.lblDate->setText("评论日期：" + str2qstr(itThis->GetDate()));
		ui.lblTitle->setText("标题：" + str2qstr(itThis->GetName()));
	}
	else
	{
		for (auto &s : arrStars)
		{
			s->setPixmap(PixEmpty);
		}
		ui.teContent->setText("");
		ui.lblDate->setText("");
		ui.lblTitle->setText("暂无评论");
	}
}

void BrowseComment::SetStars(int nStars)
{
	for (int i = 0; i < 5; ++i)
	{
		arrStars[i]->setPixmap(pixStarNil);
		if (i < nStars)
		{
			arrStars[i]->setPixmap(pixStarFul);
		}
	}
}
