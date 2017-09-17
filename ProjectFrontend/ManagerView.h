#pragma once

#include <QDialog>
#include "ui_ManagerView.h"
#include "ProfileView.h"

class ManagerView : public QDialog
{
	Q_OBJECT

public:
	ManagerView(QWidget *parent = Q_NULLPTR);
	~ManagerView();
private:
	void PrepareCook();
	void PrepareWaiter();
	bool IsAllVacance();
	void PrepareVolume();
private slots :
	void BindCook(QString qstrCook);
	void BindWaiter(QString qstrWaiter);
	void OnProfile();
	void OnSetTable();
private:
	Ui::ManagerView ui;
	string idCook;
	string idWaiter;
	Manager *pManager;
	QStandardItemModel *mdlCook;
	QStandardItemModel *mdlWaiter;
	QStandardItemModel *mdlComm;
	QStringList lstService;
};
