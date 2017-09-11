#pragma once

#include <QDialog>
#include "ui_CustomerView.h"

#include "BrowseComment.h"
#include "AddComment.h"
#include "ProfileView.h"

class CustomerView : public QDialog
{
	Q_OBJECT

public:
	CustomerView(QWidget *parent = Q_NULLPTR);
	~CustomerView();
protected:
	void paintEvent(QPaintEvent *event) override;
private slots:
	void SubmitOrder();
	void PhaseSeatPick();
	void PhaseOrderMake();
	void PhaseMealEat();
	void OnPackUp();
	void OnAddWater();
	void OnHasten();
	void OnCommentDish();
	void OnCommentWaitor();
	void OnFinish();
	void OnProfile();
private:
	void PrepareSeats();
	bool IsNoVacance();
	void SeatClicked(int num);
	void HideAll();
	void Subtotal(int nCost,int nRow,int nCol);
	void PrepareMenu();
	void MyResize(int w, int h);
	void PrepareOrder();
private:
	Ui::CustomerView ui;
	int nSeat;
	QVector<QPushButton *> matSeat;
	Customer *pCustomer;
	Waitor *pWaitor;
	int nTotal;
};
