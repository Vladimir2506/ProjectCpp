#pragma once

#include <QDialog>
#include "ui_OrderSupervise.h"

class OrderSupervise : public QDialog
{
	Q_OBJECT

public:
	OrderSupervise(QWidget *parent = Q_NULLPTR);
	~OrderSupervise();
protected:
	virtual void paintEvent(QPaintEvent *event) override;
private slots:
	void OnDelta();
	void NewLine();
	void DelLine();
	void OnSelected(QModelIndex qInd);
	void NextOne();
	void BackOne();
	void OnSaveClick();
	void OnUndoClick();
	void OnAddClick();
	void OnDelClick();
private:
	void PrepareOrder();
	void InitModel();
	bool IsEmptyAll();
	bool IsFullNow();
	void CheckDataValidity(QStandardItemModel *mdl);
	void ResolveDelta();
private:
	Ui::OrderSupervise ui;
	QStandardItemModel *mdlFoodMap;
	map<string, Order>::iterator itThis;
	bool bDelta;
	bool bLastEmpty;
	bool bSel;
	int nSel;
};
