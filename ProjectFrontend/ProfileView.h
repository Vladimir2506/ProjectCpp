#pragma once

#include <QDialog>
#include "ui_ProfileView.h"

class ProfileView : public QDialog
{
	Q_OBJECT

public:
	ProfileView(QWidget *parent = Q_NULLPTR);
	~ProfileView();
protected:
	void paintEvent(QPaintEvent *event) override;
private slots:
	void OnDelta();
	void OnSave();
	void OnUndo();
	void BindOrder(QString qstrId);
private:
	void MyResize(int w, int h);
	bool CheckPW();
	bool CheckPhone();
	bool CheckDeux();
	void PrepareInfo();
	void PrepareOrders(const string &idOrder);
	void PrepareComments();
private:
	Ui::ProfileView ui;
	People *pMe;
	bool bDelta;
	QStandardItemModel *mdlOrders;
	QStandardItemModel *mdlComments;
	QPixmap pixRight;
	QPixmap pixWrong;
	QPixmap pixNil;
	string idOrder;
	vector<string> myComments;
	QList<QString> myOrders;
};
