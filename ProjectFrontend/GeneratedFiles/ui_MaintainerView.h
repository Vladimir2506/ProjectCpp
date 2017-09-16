/********************************************************************************
** Form generated from reading UI file 'MaintainerView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTAINERVIEW_H
#define UI_MAINTAINERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_MaintainerView
{
public:
    QGroupBox *gbMenu;
    QTableView *tbMenu;
    QPushButton *btnAddMenu;
    QPushButton *btnDelMenu;
    QPushButton *btnSaveMenu;
    QPushButton *btnUndoMenu;
    QGroupBox *gbAccount;
    QComboBox *cbCata;
    QLabel *lblCata;
    QTableView *tbUser;
    QLabel *lblCommit;
    QPushButton *btnAddUser;
    QPushButton *btnDelUser;
    QPushButton *btnSaveUser;
    QPushButton *btnUndoUser;
    QLabel *lblInfo;
    QPushButton *btnComment;
    QPushButton *btnOrder;
    QLabel *lblMaintainerBGN;

    void setupUi(QDialog *MaintainerView)
    {
        if (MaintainerView->objectName().isEmpty())
            MaintainerView->setObjectName(QStringLiteral("MaintainerView"));
        MaintainerView->setWindowModality(Qt::WindowModal);
        MaintainerView->resize(1500, 900);
        MaintainerView->setMinimumSize(QSize(1500, 900));
        MaintainerView->setMaximumSize(QSize(1500, 900));
        gbMenu = new QGroupBox(MaintainerView);
        gbMenu->setObjectName(QStringLiteral("gbMenu"));
        gbMenu->setGeometry(QRect(25, 225, 700, 650));
        gbMenu->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tbMenu = new QTableView(gbMenu);
        tbMenu->setObjectName(QStringLiteral("tbMenu"));
        tbMenu->setGeometry(QRect(50, 50, 600, 450));
        tbMenu->setSelectionMode(QAbstractItemView::SingleSelection);
        tbMenu->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbMenu->setSortingEnabled(true);
        tbMenu->setCornerButtonEnabled(true);
        tbMenu->horizontalHeader()->setMinimumSectionSize(40);
        tbMenu->verticalHeader()->setDefaultSectionSize(35);
        btnAddMenu = new QPushButton(gbMenu);
        btnAddMenu->setObjectName(QStringLiteral("btnAddMenu"));
        btnAddMenu->setGeometry(QRect(75, 550, 100, 40));
        btnDelMenu = new QPushButton(gbMenu);
        btnDelMenu->setObjectName(QStringLiteral("btnDelMenu"));
        btnDelMenu->setGeometry(QRect(225, 550, 100, 40));
        btnSaveMenu = new QPushButton(gbMenu);
        btnSaveMenu->setObjectName(QStringLiteral("btnSaveMenu"));
        btnSaveMenu->setGeometry(QRect(375, 550, 100, 40));
        btnUndoMenu = new QPushButton(gbMenu);
        btnUndoMenu->setObjectName(QStringLiteral("btnUndoMenu"));
        btnUndoMenu->setGeometry(QRect(525, 550, 100, 40));
        gbAccount = new QGroupBox(MaintainerView);
        gbAccount->setObjectName(QStringLiteral("gbAccount"));
        gbAccount->setGeometry(QRect(775, 175, 700, 700));
        gbAccount->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cbCata = new QComboBox(gbAccount);
        cbCata->setObjectName(QStringLiteral("cbCata"));
        cbCata->setGeometry(QRect(300, 50, 125, 25));
        cbCata->setEditable(false);
        lblCata = new QLabel(gbAccount);
        lblCata->setObjectName(QStringLiteral("lblCata"));
        lblCata->setGeometry(QRect(125, 50, 125, 25));
        tbUser = new QTableView(gbAccount);
        tbUser->setObjectName(QStringLiteral("tbUser"));
        tbUser->setGeometry(QRect(50, 100, 600, 450));
        tbUser->setSelectionMode(QAbstractItemView::SingleSelection);
        tbUser->setSelectionBehavior(QAbstractItemView::SelectRows);
        lblCommit = new QLabel(gbAccount);
        lblCommit->setObjectName(QStringLiteral("lblCommit"));
        lblCommit->setGeometry(QRect(525, 50, 25, 25));
        btnAddUser = new QPushButton(gbAccount);
        btnAddUser->setObjectName(QStringLiteral("btnAddUser"));
        btnAddUser->setGeometry(QRect(75, 600, 100, 40));
        btnDelUser = new QPushButton(gbAccount);
        btnDelUser->setObjectName(QStringLiteral("btnDelUser"));
        btnDelUser->setGeometry(QRect(225, 600, 100, 40));
        btnSaveUser = new QPushButton(gbAccount);
        btnSaveUser->setObjectName(QStringLiteral("btnSaveUser"));
        btnSaveUser->setGeometry(QRect(375, 600, 100, 40));
        btnUndoUser = new QPushButton(gbAccount);
        btnUndoUser->setObjectName(QStringLiteral("btnUndoUser"));
        btnUndoUser->setGeometry(QRect(525, 600, 100, 40));
        lblInfo = new QLabel(MaintainerView);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        lblInfo->setGeometry(QRect(25, 175, 400, 25));
        lblInfo->setAlignment(Qt::AlignCenter);
        btnComment = new QPushButton(MaintainerView);
        btnComment->setObjectName(QStringLiteral("btnComment"));
        btnComment->setGeometry(QRect(450, 175, 125, 40));
        btnOrder = new QPushButton(MaintainerView);
        btnOrder->setObjectName(QStringLiteral("btnOrder"));
        btnOrder->setGeometry(QRect(600, 175, 125, 40));
        lblMaintainerBGN = new QLabel(MaintainerView);
        lblMaintainerBGN->setObjectName(QStringLiteral("lblMaintainerBGN"));
        lblMaintainerBGN->setGeometry(QRect(0, 0, 1500, 900));
        lblMaintainerBGN->raise();
        gbMenu->raise();
        gbAccount->raise();
        lblInfo->raise();
        btnComment->raise();
        btnOrder->raise();

        retranslateUi(MaintainerView);
        QObject::connect(btnSaveMenu, SIGNAL(clicked()), MaintainerView, SLOT(SaveChangedMenu()));
        QObject::connect(btnUndoMenu, SIGNAL(clicked()), MaintainerView, SLOT(RecoverMenu()));
        QObject::connect(btnAddMenu, SIGNAL(clicked()), MaintainerView, SLOT(NewCuisine()));
        QObject::connect(btnDelMenu, SIGNAL(clicked()), MaintainerView, SLOT(DelCuisine()));
        QObject::connect(cbCata, SIGNAL(currentIndexChanged(int)), MaintainerView, SLOT(BindCatalogue(int)));
        QObject::connect(tbMenu, SIGNAL(clicked(QModelIndex)), MaintainerView, SLOT(OnMenuSelected(QModelIndex)));
        QObject::connect(tbUser, SIGNAL(clicked(QModelIndex)), MaintainerView, SLOT(OnUserSelected(QModelIndex)));
        QObject::connect(btnAddUser, SIGNAL(clicked()), MaintainerView, SLOT(NewUser()));
        QObject::connect(btnDelUser, SIGNAL(clicked()), MaintainerView, SLOT(DelUser()));
        QObject::connect(btnSaveUser, SIGNAL(clicked()), MaintainerView, SLOT(SaveChangedUser()));
        QObject::connect(btnUndoUser, SIGNAL(clicked()), MaintainerView, SLOT(RecoverUser()));
        QObject::connect(btnComment, SIGNAL(clicked()), MaintainerView, SLOT(OnCommentClicked()));
        QObject::connect(btnOrder, SIGNAL(clicked()), MaintainerView, SLOT(OnOrderClicked()));

        QMetaObject::connectSlotsByName(MaintainerView);
    } // setupUi

    void retranslateUi(QDialog *MaintainerView)
    {
        MaintainerView->setWindowTitle(QApplication::translate("MaintainerView", "\347\263\273\347\273\237\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        gbMenu->setTitle(QApplication::translate("MaintainerView", "\350\217\234\345\215\225\347\256\241\347\220\206", Q_NULLPTR));
        btnAddMenu->setText(QApplication::translate("MaintainerView", "\346\267\273\345\212\240\350\217\234\345\223\201", Q_NULLPTR));
        btnDelMenu->setText(QApplication::translate("MaintainerView", "\345\210\240\351\231\244\350\217\234\345\223\201", Q_NULLPTR));
        btnSaveMenu->setText(QApplication::translate("MaintainerView", "\344\277\235\345\255\230\346\224\271\345\212\250", Q_NULLPTR));
        btnUndoMenu->setText(QApplication::translate("MaintainerView", "\346\222\244\351\224\200\346\224\271\345\212\250", Q_NULLPTR));
        gbAccount->setTitle(QApplication::translate("MaintainerView", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        lblCata->setText(QApplication::translate("MaintainerView", "\351\200\211\346\213\251\347\224\250\346\210\267\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        lblCommit->setText(QString());
        btnAddUser->setText(QApplication::translate("MaintainerView", "\346\267\273\345\212\240\347\224\250\346\210\267", Q_NULLPTR));
        btnDelUser->setText(QApplication::translate("MaintainerView", "\345\210\240\351\231\244\347\224\250\346\210\267", Q_NULLPTR));
        btnSaveUser->setText(QApplication::translate("MaintainerView", "\344\277\235\345\255\230\346\224\271\345\212\250", Q_NULLPTR));
        btnUndoUser->setText(QApplication::translate("MaintainerView", "\346\222\244\351\224\200\346\224\271\345\212\250", Q_NULLPTR));
        lblInfo->setText(QString());
        btnComment->setText(QApplication::translate("MaintainerView", "\350\257\204\350\256\272\347\256\241\347\220\206", Q_NULLPTR));
        btnOrder->setText(QApplication::translate("MaintainerView", "\350\256\242\345\215\225\347\256\241\347\220\206", Q_NULLPTR));
        lblMaintainerBGN->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MaintainerView: public Ui_MaintainerView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTAINERVIEW_H
