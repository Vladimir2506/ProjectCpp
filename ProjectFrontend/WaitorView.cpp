#include "stdafx.h"
#include "WaitorView.h"

WaitorView::WaitorView(QWidget *parent)
	: QDialog(parent),
	pWaitor(dynamic_cast<Waitor*>(MainLogic::GetInstance()->pUser)),
	lstService{ "�ϲ�","��ˮ","���","�ߵ�" }
{
	ui.setupUi(this);
	if (pWaitor->IsIdle())
	{
		ui.lblInfo->setText("���ã��𾴵ķ���Ա" + str2qstr(pWaitor->GetId()));
	}
	else
	{
		ui.lblInfo->setText("���ã��𾴵ķ���Ա" + str2qstr(pWaitor->GetId()) + ",�����������Ϊ" + QString::number(pWaitor->GetTableNum() + 1));
	}
	mdlDone = new QStandardItemModel(this);
	PrepareDemand();
	PrepareDone();
	PreparePlates();
}

WaitorView::~WaitorView()
{
	pWaitor = nullptr;
	MainLogic::GetInstance()->pUser = nullptr;
}

void WaitorView::paintEvent(QPaintEvent * event)
{
	if (pWaitor->IsIdle())
	{
		ui.btnDemand->setDisabled(true);
		ui.btnServe->setDisabled(true);
	}
	else
	{
		ui.btnDemand->setDisabled(itDemand == pWaitor->m_deqTodo.end());
		ui.btnServe->setDisabled(itDish == pWaitor->m_deqReady.end());
	}
	QDialog::paintEvent(event);
}

void WaitorView::OnSelPlate(int nRow)
{
	itDish = pWaitor->m_deqReady.begin() + nRow;
}

void WaitorView::OnDemand()
{
	pWaitor->DoDemand(itDemand);
	PrepareDemand();
	PrepareDone();
}

void WaitorView::OnDeliver()
{
	pWaitor->ServePlate(itDish);
	PreparePlates();
	PrepareDone();
}

void WaitorView::OnProfile()
{
	ProfileView profile(this);
	profile.exec();
	if (pWaitor->IsIdle())
	{
		ui.lblInfo->setText("���ã��𾴵ķ���Ա" + str2qstr(pWaitor->GetId()));
	}
	else
	{
		ui.lblInfo->setText("���ã��𾴵ķ���Ա" + str2qstr(pWaitor->GetId()) + ",�����������Ϊ" + QString::number(pWaitor->GetTableNum()));
	}
}

void WaitorView::OnSelDemand(int nRow)
{
	itDemand = pWaitor->m_deqTodo.begin() + nRow;
}

void WaitorView::PreparePlates()
{
	ui.lstPlate->clear();
	for (auto &pl : pWaitor->m_deqReady)
	{
		ui.lstPlate->addItem(str2qstr(pl.first.GetName()));
	}
	itDish = pWaitor->m_deqReady.begin();
}

void WaitorView::PrepareDemand()
{
	ui.lstDemand->clear();
	for (auto &dm : pWaitor->m_deqTodo)
	{
		ui.lstDemand->addItem(new QListWidgetItem(lstService[dm]));
	}
	itDemand = pWaitor->m_deqTodo.begin();
}

void WaitorView::PrepareDone()
{
	ui.tbDone->reset();
	mdlDone->clear();
	mdlDone->setColumnCount(2);
	mdlDone->setHeaderData(0, Qt::Horizontal, "������Ŀ");
	mdlDone->setHeaderData(1, Qt::Horizontal, "�������");
	int nRow = 0;
	for (auto & ser : pWaitor->GetServDone())
	{
		mdlDone->setItem(nRow, 0, new QStandardItem(lstService[nRow]));
		mdlDone->setItem(nRow, 1, new QStandardItem(QString::number(ser)));
		++nRow;
	}
	ui.tbDone->setModel(mdlDone);
}
