/********************************************************************************
** Form generated from reading UI file 'WaitorView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITORVIEW_H
#define UI_WAITORVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_WaitorView
{
public:
    QLabel *lblInfo;
    QGroupBox *gbTodo;
    QListWidget *lstPlate;
    QListWidget *lstDemand;
    QLabel *lblDemand;
    QLabel *lblPlate;
    QPushButton *btnServe;
    QPushButton *btnDemand;
    QGroupBox *gbDone;
    QTableView *tbDone;
    QPushButton *btnProfile;
    QLabel *lblWaitorBGN;

    void setupUi(QDialog *WaitorView)
    {
        if (WaitorView->objectName().isEmpty())
            WaitorView->setObjectName(QStringLiteral("WaitorView"));
        WaitorView->resize(925, 750);
        WaitorView->setMinimumSize(QSize(925, 750));
        WaitorView->setMaximumSize(QSize(925, 750));
        lblInfo = new QLabel(WaitorView);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        lblInfo->setGeometry(QRect(25, 175, 350, 25));
        gbTodo = new QGroupBox(WaitorView);
        gbTodo->setObjectName(QStringLiteral("gbTodo"));
        gbTodo->setGeometry(QRect(25, 225, 525, 500));
        lstPlate = new QListWidget(gbTodo);
        lstPlate->setObjectName(QStringLiteral("lstPlate"));
        lstPlate->setGeometry(QRect(25, 75, 225, 325));
        lstPlate->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lstDemand = new QListWidget(gbTodo);
        lstDemand->setObjectName(QStringLiteral("lstDemand"));
        lstDemand->setGeometry(QRect(270, 75, 225, 325));
        lstDemand->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lstDemand->setSelectionMode(QAbstractItemView::SingleSelection);
        lblDemand = new QLabel(gbTodo);
        lblDemand->setObjectName(QStringLiteral("lblDemand"));
        lblDemand->setGeometry(QRect(325, 35, 125, 25));
        lblDemand->setAlignment(Qt::AlignCenter);
        lblPlate = new QLabel(gbTodo);
        lblPlate->setObjectName(QStringLiteral("lblPlate"));
        lblPlate->setGeometry(QRect(75, 35, 125, 25));
        lblPlate->setAlignment(Qt::AlignCenter);
        btnServe = new QPushButton(gbTodo);
        btnServe->setObjectName(QStringLiteral("btnServe"));
        btnServe->setGeometry(QRect(75, 425, 125, 40));
        btnDemand = new QPushButton(gbTodo);
        btnDemand->setObjectName(QStringLiteral("btnDemand"));
        btnDemand->setGeometry(QRect(325, 425, 125, 40));
        gbDone = new QGroupBox(WaitorView);
        gbDone->setObjectName(QStringLiteral("gbDone"));
        gbDone->setGeometry(QRect(575, 175, 325, 550));
        tbDone = new QTableView(gbDone);
        tbDone->setObjectName(QStringLiteral("tbDone"));
        tbDone->setGeometry(QRect(25, 25, 275, 500));
        tbDone->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbDone->setSelectionMode(QAbstractItemView::NoSelection);
        btnProfile = new QPushButton(WaitorView);
        btnProfile->setObjectName(QStringLiteral("btnProfile"));
        btnProfile->setGeometry(QRect(425, 175, 100, 40));
        lblWaitorBGN = new QLabel(WaitorView);
        lblWaitorBGN->setObjectName(QStringLiteral("lblWaitorBGN"));
        lblWaitorBGN->setGeometry(QRect(0, 0, 925, 750));
        lblWaitorBGN->raise();
        lblInfo->raise();
        gbTodo->raise();
        gbDone->raise();
        btnProfile->raise();

        retranslateUi(WaitorView);
        QObject::connect(lstDemand, SIGNAL(currentRowChanged(int)), WaitorView, SLOT(OnSelDemand(int)));
        QObject::connect(lstPlate, SIGNAL(currentRowChanged(int)), WaitorView, SLOT(OnSelPlate(int)));
        QObject::connect(btnDemand, SIGNAL(clicked()), WaitorView, SLOT(OnDemand()));
        QObject::connect(btnServe, SIGNAL(clicked()), WaitorView, SLOT(OnDeliver()));
        QObject::connect(btnProfile, SIGNAL(clicked()), WaitorView, SLOT(OnProfile()));

        QMetaObject::connectSlotsByName(WaitorView);
    } // setupUi

    void retranslateUi(QDialog *WaitorView)
    {
        WaitorView->setWindowTitle(QApplication::translate("WaitorView", "\346\234\215\345\212\241\345\221\230", Q_NULLPTR));
        lblInfo->setText(QString());
        gbTodo->setTitle(QApplication::translate("WaitorView", "\345\275\223\345\211\215\344\273\273\345\212\241\346\270\205\345\215\225", Q_NULLPTR));
        lblDemand->setText(QApplication::translate("WaitorView", "\351\241\276\345\256\242\351\234\200\350\246\201\347\232\204\346\234\215\345\212\241", Q_NULLPTR));
        lblPlate->setText(QApplication::translate("WaitorView", "\345\267\262\345\201\232\345\245\275\347\232\204\350\217\234\345\223\201", Q_NULLPTR));
        btnServe->setText(QApplication::translate("WaitorView", "\346\264\276\351\200\201\351\200\211\345\256\232\350\217\234\345\223\201", Q_NULLPTR));
        btnDemand->setText(QApplication::translate("WaitorView", "\345\256\214\346\210\220\351\200\211\345\256\232\346\234\215\345\212\241", Q_NULLPTR));
        gbDone->setTitle(QApplication::translate("WaitorView", "\345\267\262\345\256\214\346\210\220\347\232\204\344\273\273\345\212\241", Q_NULLPTR));
        btnProfile->setText(QApplication::translate("WaitorView", "\344\270\252\344\272\272\350\265\204\346\226\231", Q_NULLPTR));
        lblWaitorBGN->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WaitorView: public Ui_WaitorView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITORVIEW_H
