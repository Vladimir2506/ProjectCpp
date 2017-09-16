#include "stdafx.h"
#include "CookView.h"

CookView::CookView(QWidget *parent)
	: QDialog(parent),
	pCook(dynamic_cast<Cook*>(MainLogic::GetInstance()->pUser))
{
	ui.setupUi(this);
	ui.lblInfo->setText("���ã��𾴵ĳ�ʦ" + str2qstr(pCook->GetName()));
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

void CookView::OnProfile()
{
	ProfileView profile(this);
	profile.exec();
	ui.lblInfo->setText("���ã��𾴵ĳ�ʦ" + str2qstr(pCook->GetName()));
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
	mdlDone->setHeaderData(0, Qt::Horizontal, "��Ʒ��");
	mdlDone->setHeaderData(1, Qt::Horizontal, "�������");
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