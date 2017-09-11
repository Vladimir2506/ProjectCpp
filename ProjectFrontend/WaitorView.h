#pragma once

#include <QDialog>
#include "ui_WaitorView.h"
#include "ProfileView.h"

class WaitorView : public QDialog
{
	Q_OBJECT

public:
	WaitorView(QWidget *parent = Q_NULLPTR);
	~WaitorView();
protected:
	virtual void paintEvent(QPaintEvent *event) override;
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
	Ui::WaitorView ui;
	Waitor *pWaitor;
	deque<pair<Cuisine, Order*>>::iterator itDish;
	deque<int>::iterator itDemand;
	QStandardItemModel *mdlDone;
	QStringList lstService;
};
