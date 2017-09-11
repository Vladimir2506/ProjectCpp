#pragma once

#include <QDialog>
#include "ui_MaintainerView.h"

#include "CommentSupervise.h"
#include "OrderSupervise.h"

class MaintainerView : public QDialog
{
	Q_OBJECT

public:
	MaintainerView(QWidget *parent = Q_NULLPTR);
	~MaintainerView();
private slots:
	void OnMenuSelected(QModelIndex qInd);
	void OnUserSelected(QModelIndex qInd);
	void OnMenuDelta(QStandardItem *pDelta);
	void OnUserDelta(QStandardItem *pDelta);
	void SaveChangedMenu();
	void RecoverMenu();
	void NewCuisine();
	void DelCuisine();
	void NewUser();
	void SaveChangedUser();
	void RecoverUser();
	void DelUser();
	void BindCatalogue(int nSel);
	void OnCommentClicked();
	void OnOrderClicked();
protected:
	virtual void paintEvent(QPaintEvent *event) override;
private:
	void PrepareMenu();
	void PrepareUser();
	void ResolveDeltaMenu();
	void ResolveDeltaUser();
	void CustomerDelta();
	void CookDelta();
	void WaitorDelta();
	void ManagerDelta();
	void MaintainerDelta();
	void CustomerPrepare();
	void CookPrepare();
	void WaitorPrepare();
	void ManagerPrepare();
	void MaintainerPrepare();
	void CheckDataValidity(QStandardItemModel *mdl);
	void ResetUserButtons();
private:
	Ui::MaintainerView ui;
	QStandardItemModel *mdlMenu;	//Frontend's menu
	bool bMenuDelta;				//Menu is changed
	bool bMenuSelect;				//Item is selected
	bool bMenuLastEmpty;			//Menu's last row is empty
	int nMenuSel;					//Select row of menu
	int nCata;						//The cata on display
	QStringList lstCata;			//Content of catalogues
	QPixmap pixMod;
	QPixmap pixCom;
	QStandardItemModel *mdlUser;	//Frontend's user
	bool bUserDelta;				//User changed
	bool bUserSelect;				//User is  selected
	bool bUserLastEmpty;			//User's last row is empty
	int nUserSel;					//Select row of user
	Maintainer *pMaintainer;
};
