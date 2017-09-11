#include "stdafx.h"
#include "CookView.h"

CookView::CookView(QWidget *parent)
	: QDialog(parent),
	pCook(dynamic_cast<Cook*>(MainLogic::GetInstance()->pUser))
{
	ui.setupUi(this);
	ui.lblInfo->setText("您好！尊敬的厨师" + str2qstr(pCook->GetName()));
	mdlDone = new QStandardItemModel(this);
	PrepareDone();
	PrepareTodo();
}

CookView::~CookView()
{
	pCook = nullptr;
	MainLogic::GetInstance()->pUser = nullptr;
}

void CookView::paintEvent(QPaintEvent * event)
{
	ui.btnFinish->setDisabled(itThis == pCook->m_deqTodo.end());
	QDialog::paintEvent(event);
}

void CookView::OnSelect(int nRow)
{
	itThis = pCook->m_deqTodo.begin() + nRow;
}

void CookView::PrepareTodo()
{
	ui.lstTodo->clear();
	for (auto d : pCook->GetToDoList())
	{
		ui.lstTodo->addItem(str2qstr(d.first.GetName()));
	}
	itThis = pCook->m_deqTodo.begin();
}

void CookView::PrepareDone()
{
	ui.tbDone->reset();
	mdlDone->clear();
	mdlDone->setColumnCount(2);
	mdlDone->setHeaderData(0, Qt::Horizontal, "菜品名");
	mdlDone->setHeaderData(1, Qt::Horizontal, "已完成量");
	int nRow = 0;
	for (auto & d : pCook->GetWorkDone())
	{
		mdlDone->setItem(nRow, 0, new QStandardItem(str2qstr(d.first.GetName())));
		mdlDone->setItem(nRow, 1, new QStandardItem(QString::number(d.second)));
		++nRow;
	}
	ui.tbDone->setModel(mdlDone);
}

void CookView::CookOne()
{
	pCook->DoCooking(itThis);
	PrepareDone();
	PrepareTodo();
}