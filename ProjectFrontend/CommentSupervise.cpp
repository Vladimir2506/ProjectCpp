#include "stdafx.h"
#include "CommentSupervise.h"

CommentSupervise::CommentSupervise(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//Data init
	itThis = MainLogic::s_currentComments.begin();
	//Stars Init
	lblStars = { ui.lbls1,ui.lbls2,ui.lbls3,ui.lbls4,ui.lbls5 };
	pixStarFul.load("starful.png");
	pixStarNil.load("starnil.png");
	//Buttons Init
	ui.btnUndo->setDisabled(true);
	PrepareComment();
}

CommentSupervise::~CommentSupervise()
{
}

void CommentSupervise::paintEvent(QPaintEvent * event)
{
	if (bDelta)
	{
		ui.btnAdd->setDisabled(true);
		ui.btnNext->setDisabled(true);
		ui.btnBack->setDisabled(true);
		if (IsNowFull() || (IsNowEmpty() && itThis != MainLogic::s_currentComments.end()))
		{
			ui.btnSave->setDisabled(false);
		}
		else
		{
			ui.btnSave->setDisabled(true);
		}
		ui.btnUndo->setDisabled(false);
	}
	else
	{
		if (IsNowEmpty())
		{
			ui.btnAdd->setDisabled(true);
		}
		else
		{
			ui.btnAdd->setDisabled(false);
		}
		if (itThis != MainLogic::s_currentComments.end())
		{
			ui.btnNext->setDisabled(false);
		}
		else
		{
			ui.btnNext->setDisabled(true);
		}
		if (itThis != MainLogic::s_currentComments.begin())
		{
			ui.btnBack->setDisabled(false);
		}
		else
		{
			ui.btnBack->setDisabled(true);
		}
		ui.btnSave->setDisabled(true);
		ui.btnUndo->setDisabled(true);
	}
	QDialog::paintEvent(event);
}

void CommentSupervise::SetStars(int nStar)
{
	for (int i = 0; i < 5; ++i)
	{
		lblStars[i]->setPixmap(pixStarNil);
		if (i < nStar)
		{
			lblStars[i]->setPixmap(pixStarFul);
		}
	}
}

void CommentSupervise::OnDelClick()
{
	EmptyNow();
}

void CommentSupervise::OnSaveClick()
{
	if (IsNowFull())
	{
		if (itThis == MainLogic::s_currentComments.end())
		{
			Comment tmp;
			tmp.SetId(qstr2str(ui.leComId->text()));
			tmp.SetName(qstr2str(ui.leTitle->text()));
			tmp.SetUserId(qstr2str(ui.leSrcId->text()));
			tmp.SetDishId(qstr2str(ui.leDestId->text()));
			tmp.SetDate(qstr2str(ui.deDate->text()));
			tmp.m_nStar = ui.sbStar->value();
			tmp.m_strContent = qstr2str(ui.teContent->toPlainText());
			MainLogic::s_currentComments.insert(make_pair(tmp.GetId(), tmp));
			itThis = MainLogic::s_currentComments.find(tmp.GetId());
		}
		else
		{
			itThis->second.SetId(qstr2str(ui.leComId->text()));
			itThis->second.SetName(qstr2str(ui.leTitle->text()));
			itThis->second.SetUserId(qstr2str(ui.leSrcId->text()));
			itThis->second.SetDishId(qstr2str(ui.leDestId->text()));
			itThis->second.SetDate(qstr2str(ui.deDate->text()));
			itThis->second.m_nStar = ui.sbStar->value();
			itThis->second.m_strContent = qstr2str(ui.teContent->toPlainText());
		}
	}
	else
	{
		if (itThis == MainLogic::s_currentComments.end())
		{
			return;
		}
		else
		{
			itThis->second.DeleteMe(MainLogic::GetInstance()->MainDB);
			MainLogic::s_currentComments.erase(itThis++);
		}
	}
	bDelta = false;
}

void CommentSupervise::OnUndoClick()
{
	PrepareComment();
}

void CommentSupervise::OnAddClick()
{
	itThis = MainLogic::s_currentComments.end();
	PrepareComment();
}

void CommentSupervise::BackOne()
{
	if (itThis != MainLogic::s_currentComments.begin())
	{
		--itThis;
	}
	PrepareComment();
}

void CommentSupervise::NextOne()
{
	if (itThis != MainLogic::s_currentComments.end())
	{
		++itThis;
	}
	PrepareComment();
}

void CommentSupervise::OnDelta()
{
	bDelta = true;
}

void CommentSupervise::PrepareComment()
{
	if (itThis == MainLogic::s_currentComments.end())
	{
		EmptyNow();
	}
	else
	{
		ui.leComId->setText(str2qstr(itThis->second.GetId()));
		ui.leSrcId->setText(str2qstr(itThis->second.GetUserId()));
		ui.leDestId->setText(str2qstr(itThis->second.GetDishId()));
		ui.deDate->setDate(QDate::fromString(str2qstr(itThis->second.GetDate()), "yyyy/MM/dd"));
		ui.leTitle->setText(str2qstr(itThis->second.GetName()));
		ui.teContent->setText(str2qstr(itThis->second.m_strContent));
		ui.sbStar->setValue(itThis->second.m_nStar);
	}
	bDelta = false;
}

void CommentSupervise::EmptyNow()
{
	ui.deDate->setDate(QDate::currentDate());
	ui.leComId->setText("");
	ui.leSrcId->setText("");
	ui.leDestId->setText("");
	ui.leTitle->setText("");
	ui.teContent->setText("");
	ui.sbStar->setValue(0);
}

bool CommentSupervise::IsNowEmpty()
{
	return ui.leComId->text().isEmpty()
		&& ui.leDestId->text().isEmpty()
		&& ui.leSrcId->text().isEmpty()
		&& ui.leTitle->text().isEmpty()
		&& ui.teContent->toPlainText().isEmpty();
}

bool CommentSupervise::IsNowFull()
{
	return !ui.leComId->text().isEmpty()
		&& !ui.leDestId->text().isEmpty()
		&& !ui.leSrcId->text().isEmpty()
		&& !ui.leTitle->text().isEmpty()
		&& !ui.teContent->toPlainText().isEmpty();
}
