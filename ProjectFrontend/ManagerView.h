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
	void PrepareWaitor();
	bool IsAllVacance();
	void PrepareVolume();
private slots :
	void BindCook(QString qstrCook);
	void BindWaitor(QString qstrWaitor);
	void OnProfile();
	void OnSetTable();
private:
	Ui::ManagerView ui;
	string idCook;
	string idWaitor;
	Manager *pManager;
	QStandardItemModel *mdlCook;
	QStandardItemModel *mdlWaitor;
	QStandardItemModel *mdlComm;
	QStringList lstService;
};
