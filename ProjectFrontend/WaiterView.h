#pragma once

#include <QDialog>
#include "ui_WaiterView.h"
#include "ProfileView.h"

class WaiterView : public QDialog
{
	Q_OBJECT

public:
	WaiterView(QWidget *parent = Q_NULLPTR);
	~WaiterView();
protected:
	void paintEvent(QPaintEvent *event) override;
private slots:
	void OnSelDemand(int nRow);
	void OnSelPlate(int nRow);
	void OnDemand();
	void OnDeliver();
	void OnProfile();
private:
	void PreparePlates();
	void PrepareDemand();
	void PrepareDone();
private:
	Ui::WaiterView ui;
	Waiter *pWaiter;
	deque<pair<Cuisine, Order*>>::iterator itDish;
	deque<int>::iterator itDemand;
	QStandardItemModel *mdlDone;
	QStringList lstService;
};
