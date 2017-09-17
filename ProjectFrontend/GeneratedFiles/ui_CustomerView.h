/********************************************************************************
** Form generated from reading UI file 'CustomerView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERVIEW_H
#define UI_CUSTOMERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerView
{
public:
    QGroupBox *gbSeatPick;
    QLabel *lblInfo;
    QLabel *lblHint;
    QGroupBox *gbMenu;
    QTableWidget *tbMenuDisp;
    QLabel *lblTotal;
    QPushButton *btnSubmit;
    QPushButton *btnReturn;
    QGroupBox *gbOrder;
    QTableWidget *tbOrder;
    QProgressBar *pbGeneral;
    QPushButton *btnFinish;
    QLabel *lblProgress;
    QGroupBox *gbInstruction;
    QLabel *lblWaiter;
    QPushButton *btnAddWater;
    QPushButton *btnPackUp;
    QPushButton *btnHasten;
    QPushButton *btnComDish;
    QPushButton *btnComWaiter;
    QPushButton *btnProfile;
    QLabel *lblCustomerBGN;

    void setupUi(QDialog *CustomerView)
    {
        if (CustomerView->objectName().isEmpty())
            CustomerView->setObjectName(QStringLiteral("CustomerView"));
        CustomerView->setWindowModality(Qt::WindowModal);
        CustomerView->resize(1003, 850);
        gbSeatPick = new QGroupBox(CustomerView);
        gbSeatPick->setObjectName(QStringLiteral("gbSeatPick"));
        gbSeatPick->setGeometry(QRect(25, 275, 550, 550));
        gbSeatPick->setAlignment(Qt::AlignCenter);
        lblInfo = new QLabel(CustomerView);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        lblInfo->setGeometry(QRect(25, 175, 400, 25));
        lblInfo->setAlignment(Qt::AlignCenter);
        lblHint = new QLabel(CustomerView);
        lblHint->setObjectName(QStringLiteral("lblHint"));
        lblHint->setGeometry(QRect(25, 225, 600, 25));
        gbMenu = new QGroupBox(CustomerView);
        gbMenu->setObjectName(QStringLiteral("gbMenu"));
        gbMenu->setGeometry(QRect(25, 225, 850, 650));
        tbMenuDisp = new QTableWidget(gbMenu);
        tbMenuDisp->setObjectName(QStringLiteral("tbMenuDisp"));
        tbMenuDisp->setGeometry(QRect(25, 25, 800, 500));
        tbMenuDisp->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbMenuDisp->setSelectionMode(QAbstractItemView::SingleSelection);
        tbMenuDisp->setSelectionBehavior(QAbstractItemView::SelectRows);
        lblTotal = new QLabel(gbMenu);
        lblTotal->setObjectName(QStringLiteral("lblTotal"));
        lblTotal->setGeometry(QRect(50, 575, 150, 40));
        btnSubmit = new QPushButton(gbMenu);
        btnSubmit->setObjectName(QStringLiteral("btnSubmit"));
        btnSubmit->setGeometry(QRect(275, 575, 150, 50));
        btnReturn = new QPushButton(gbMenu);
        btnReturn->setObjectName(QStringLiteral("btnReturn"));
        btnReturn->setGeometry(QRect(525, 575, 150, 50));
        gbOrder = new QGroupBox(CustomerView);
        gbOrder->setObjectName(QStringLiteral("gbOrder"));
        gbOrder->setGeometry(QRect(25, 225, 550, 500));
        tbOrder = new QTableWidget(gbOrder);
        tbOrder->setObjectName(QStringLiteral("tbOrder"));
        tbOrder->setGeometry(QRect(25, 25, 500, 400));
        tbOrder->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbOrder->setSelectionMode(QAbstractItemView::NoSelection);
        tbOrder->setSelectionBehavior(QAbstractItemView::SelectRows);
        pbGeneral = new QProgressBar(gbOrder);
        pbGeneral->setObjectName(QStringLiteral("pbGeneral"));
        pbGeneral->setGeometry(QRect(250, 450, 250, 25));
        pbGeneral->setValue(0);
        btnFinish = new QPushButton(gbOrder);
        btnFinish->setObjectName(QStringLiteral("btnFinish"));
        btnFinish->setGeometry(QRect(25, 440, 100, 40));
        lblProgress = new QLabel(gbOrder);
        lblProgress->setObjectName(QStringLiteral("lblProgress"));
        lblProgress->setGeometry(QRect(150, 450, 75, 25));
        gbInstruction = new QGroupBox(CustomerView);
        gbInstruction->setObjectName(QStringLiteral("gbInstruction"));
        gbInstruction->setGeometry(QRect(600, 175, 350, 550));
        lblWaiter = new QLabel(gbInstruction);
        lblWaiter->setObjectName(QStringLiteral("lblWaiter"));
        lblWaiter->setGeometry(QRect(50, 50, 250, 25));
        btnAddWater = new QPushButton(gbInstruction);
        btnAddWater->setObjectName(QStringLiteral("btnAddWater"));
        btnAddWater->setGeometry(QRect(50, 150, 100, 40));
        btnPackUp = new QPushButton(gbInstruction);
        btnPackUp->setObjectName(QStringLiteral("btnPackUp"));
        btnPackUp->setGeometry(QRect(200, 150, 100, 40));
        btnHasten = new QPushButton(gbInstruction);
        btnHasten->setObjectName(QStringLiteral("btnHasten"));
        btnHasten->setGeometry(QRect(50, 250, 100, 40));
        btnComDish = new QPushButton(gbInstruction);
        btnComDish->setObjectName(QStringLiteral("btnComDish"));
        btnComDish->setGeometry(QRect(125, 400, 125, 40));
        btnComWaiter = new QPushButton(gbInstruction);
        btnComWaiter->setObjectName(QStringLiteral("btnComWaiter"));
        btnComWaiter->setGeometry(QRect(125, 450, 125, 40));
        btnProfile = new QPushButton(CustomerView);
        btnProfile->setObjectName(QStringLiteral("btnProfile"));
        btnProfile->setGeometry(QRect(450, 175, 100, 40));
        lblCustomerBGN = new QLabel(CustomerView);
        lblCustomerBGN->setObjectName(QStringLiteral("lblCustomerBGN"));
        lblCustomerBGN->setGeometry(QRect(0, 0, 1000, 1100));
        lblCustomerBGN->raise();
        gbSeatPick->raise();
        lblInfo->raise();
        lblHint->raise();
        gbMenu->raise();
        gbOrder->raise();
        gbInstruction->raise();
        btnProfile->raise();

        retranslateUi(CustomerView);
        QObject::connect(btnReturn, SIGNAL(clicked()), CustomerView, SLOT(PhaseSeatPick()));
        QObject::connect(btnSubmit, SIGNAL(clicked()), CustomerView, SLOT(SubmitOrder()));
        QObject::connect(btnAddWater, SIGNAL(clicked()), CustomerView, SLOT(OnAddWater()));
        QObject::connect(btnPackUp, SIGNAL(clicked()), CustomerView, SLOT(OnPackUp()));
        QObject::connect(btnHasten, SIGNAL(clicked()), CustomerView, SLOT(OnHasten()));
        QObject::connect(btnFinish, SIGNAL(clicked()), CustomerView, SLOT(OnFinish()));
        QObject::connect(btnComDish, SIGNAL(clicked()), CustomerView, SLOT(OnCommentDish()));
        QObject::connect(btnComWaiter, SIGNAL(clicked()), CustomerView, SLOT(OnCommentWaiter()));
        QObject::connect(btnProfile, SIGNAL(clicked()), CustomerView, SLOT(OnProfile()));

        QMetaObject::connectSlotsByName(CustomerView);
    } // setupUi

    void retranslateUi(QDialog *CustomerView)
    {
        CustomerView->setWindowTitle(QApplication::translate("CustomerView", "\351\241\276\345\256\242", Q_NULLPTR));
        gbSeatPick->setTitle(QString());
        lblInfo->setText(QString());
        lblHint->setText(QString());
        gbMenu->setTitle(QApplication::translate("CustomerView", "\346\237\245\347\234\213\350\217\234\345\215\225\345\271\266\347\202\271\351\244\220", Q_NULLPTR));
        lblTotal->setText(QString());
        btnSubmit->setText(QApplication::translate("CustomerView", "\346\217\220\344\272\244\350\256\242\345\215\225\345\271\266\344\273\230\346\254\276", Q_NULLPTR));
        btnReturn->setText(QApplication::translate("CustomerView", "\350\277\224\345\233\236\351\207\215\346\226\260\351\200\211\346\241\214", Q_NULLPTR));
        gbOrder->setTitle(QApplication::translate("CustomerView", "\346\237\245\347\234\213\350\256\242\345\215\225\345\256\214\346\210\220\346\203\205\345\206\265", Q_NULLPTR));
        btnFinish->setText(QApplication::translate("CustomerView", "\347\224\250\351\244\220\345\256\214\346\257\225", Q_NULLPTR));
        lblProgress->setText(QApplication::translate("CustomerView", "\345\256\214\346\210\220\350\277\233\345\272\246\357\274\232", Q_NULLPTR));
        gbInstruction->setTitle(QApplication::translate("CustomerView", "\351\242\235\345\244\226\345\221\275\344\273\244", Q_NULLPTR));
        lblWaiter->setText(QString());
        btnAddWater->setText(QApplication::translate("CustomerView", "\345\212\240\346\260\264", Q_NULLPTR));
        btnPackUp->setText(QApplication::translate("CustomerView", "\346\211\223\345\214\205", Q_NULLPTR));
        btnHasten->setText(QApplication::translate("CustomerView", "\345\202\254\345\215\225", Q_NULLPTR));
        btnComDish->setText(QApplication::translate("CustomerView", "\350\257\204\344\273\267\345\267\262\347\202\271\350\217\234\345\223\201", Q_NULLPTR));
        btnComWaiter->setText(QApplication::translate("CustomerView", "\350\257\204\344\273\267\346\234\215\345\212\241\345\221\230", Q_NULLPTR));
        btnProfile->setText(QApplication::translate("CustomerView", "\344\270\252\344\272\272\350\265\204\346\226\231", Q_NULLPTR));
        lblCustomerBGN->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CustomerView: public Ui_CustomerView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERVIEW_H
