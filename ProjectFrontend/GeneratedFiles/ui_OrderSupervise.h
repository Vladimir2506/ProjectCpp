/********************************************************************************
** Form generated from reading UI file 'OrderSupervise.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERSUPERVISE_H
#define UI_ORDERSUPERVISE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_OrderSupervise
{
public:
    QPushButton *btnBack;
    QPushButton *btnNext;
    QGroupBox *gbContent;
    QTableView *tbFood;
    QPushButton *btnNLine;
    QPushButton *btnDLine;
    QGroupBox *gbProperty;
    QLineEdit *leID;
    QLineEdit *leName;
    QLineEdit *leWaitor;
    QLineEdit *leCustomer;
    QLabel *lblID;
    QLabel *lblName;
    QLabel *lblWaitorID;
    QLabel *lblCustomer;
    QLabel *lblTableNO;
    QLineEdit *leTableNO;
    QPushButton *btnSave;
    QPushButton *btnUndo;
    QPushButton *btnAdd;
    QPushButton *btnDel;

    void setupUi(QDialog *OrderSupervise)
    {
        if (OrderSupervise->objectName().isEmpty())
            OrderSupervise->setObjectName(QStringLiteral("OrderSupervise"));
        OrderSupervise->resize(900, 500);
        OrderSupervise->setMinimumSize(QSize(900, 500));
        OrderSupervise->setMaximumSize(QSize(900, 500));
        btnBack = new QPushButton(OrderSupervise);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(25, 25, 40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral("back.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon);
        btnBack->setIconSize(QSize(25, 25));
        btnNext = new QPushButton(OrderSupervise);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setGeometry(QRect(75, 25, 40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral("next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon1);
        btnNext->setIconSize(QSize(25, 25));
        gbContent = new QGroupBox(OrderSupervise);
        gbContent->setObjectName(QStringLiteral("gbContent"));
        gbContent->setGeometry(QRect(450, 25, 425, 450));
        tbFood = new QTableView(gbContent);
        tbFood->setObjectName(QStringLiteral("tbFood"));
        tbFood->setGeometry(QRect(50, 50, 325, 325));
        tbFood->setSelectionMode(QAbstractItemView::SingleSelection);
        tbFood->setSelectionBehavior(QAbstractItemView::SelectRows);
        btnNLine = new QPushButton(gbContent);
        btnNLine->setObjectName(QStringLiteral("btnNLine"));
        btnNLine->setGeometry(QRect(75, 390, 100, 40));
        btnDLine = new QPushButton(gbContent);
        btnDLine->setObjectName(QStringLiteral("btnDLine"));
        btnDLine->setGeometry(QRect(250, 390, 100, 40));
        gbProperty = new QGroupBox(OrderSupervise);
        gbProperty->setObjectName(QStringLiteral("gbProperty"));
        gbProperty->setGeometry(QRect(25, 75, 410, 400));
        leID = new QLineEdit(gbProperty);
        leID->setObjectName(QStringLiteral("leID"));
        leID->setGeometry(QRect(200, 50, 150, 25));
        leName = new QLineEdit(gbProperty);
        leName->setObjectName(QStringLiteral("leName"));
        leName->setGeometry(QRect(200, 125, 150, 25));
        leWaitor = new QLineEdit(gbProperty);
        leWaitor->setObjectName(QStringLiteral("leWaitor"));
        leWaitor->setGeometry(QRect(200, 200, 150, 25));
        leCustomer = new QLineEdit(gbProperty);
        leCustomer->setObjectName(QStringLiteral("leCustomer"));
        leCustomer->setGeometry(QRect(200, 275, 150, 25));
        lblID = new QLabel(gbProperty);
        lblID->setObjectName(QStringLiteral("lblID"));
        lblID->setGeometry(QRect(50, 50, 125, 25));
        lblName = new QLabel(gbProperty);
        lblName->setObjectName(QStringLiteral("lblName"));
        lblName->setGeometry(QRect(50, 125, 125, 25));
        lblWaitorID = new QLabel(gbProperty);
        lblWaitorID->setObjectName(QStringLiteral("lblWaitorID"));
        lblWaitorID->setGeometry(QRect(50, 200, 125, 25));
        lblCustomer = new QLabel(gbProperty);
        lblCustomer->setObjectName(QStringLiteral("lblCustomer"));
        lblCustomer->setGeometry(QRect(50, 275, 125, 25));
        lblTableNO = new QLabel(gbProperty);
        lblTableNO->setObjectName(QStringLiteral("lblTableNO"));
        lblTableNO->setGeometry(QRect(50, 350, 125, 25));
        leTableNO = new QLineEdit(gbProperty);
        leTableNO->setObjectName(QStringLiteral("leTableNO"));
        leTableNO->setGeometry(QRect(200, 350, 150, 25));
        btnSave = new QPushButton(OrderSupervise);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(125, 25, 100, 40));
        btnUndo = new QPushButton(OrderSupervise);
        btnUndo->setObjectName(QStringLiteral("btnUndo"));
        btnUndo->setGeometry(QRect(235, 25, 100, 40));
        btnAdd = new QPushButton(OrderSupervise);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(345, 25, 40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral("add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon2);
        btnAdd->setIconSize(QSize(25, 25));
        btnDel = new QPushButton(OrderSupervise);
        btnDel->setObjectName(QStringLiteral("btnDel"));
        btnDel->setGeometry(QRect(395, 25, 40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral("subtract.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDel->setIcon(icon3);
        btnDel->setIconSize(QSize(25, 25));

        retranslateUi(OrderSupervise);
        QObject::connect(leID, SIGNAL(textEdited(QString)), OrderSupervise, SLOT(OnDelta()));
        QObject::connect(leName, SIGNAL(textEdited(QString)), OrderSupervise, SLOT(OnDelta()));
        QObject::connect(leWaitor, SIGNAL(textEdited(QString)), OrderSupervise, SLOT(OnDelta()));
        QObject::connect(leCustomer, SIGNAL(textEdited(QString)), OrderSupervise, SLOT(OnDelta()));
        QObject::connect(tbFood, SIGNAL(clicked(QModelIndex)), OrderSupervise, SLOT(OnSelected(QModelIndex)));
        QObject::connect(btnNLine, SIGNAL(clicked()), OrderSupervise, SLOT(NewLine()));
        QObject::connect(btnDLine, SIGNAL(clicked()), OrderSupervise, SLOT(DelLine()));
        QObject::connect(btnAdd, SIGNAL(clicked()), OrderSupervise, SLOT(OnAddClick()));
        QObject::connect(btnDel, SIGNAL(clicked()), OrderSupervise, SLOT(OnDelClick()));
        QObject::connect(btnBack, SIGNAL(clicked()), OrderSupervise, SLOT(BackOne()));
        QObject::connect(btnNext, SIGNAL(clicked()), OrderSupervise, SLOT(NextOne()));
        QObject::connect(btnSave, SIGNAL(clicked()), OrderSupervise, SLOT(OnSaveClick()));
        QObject::connect(btnUndo, SIGNAL(clicked()), OrderSupervise, SLOT(OnUndoClick()));
        QObject::connect(leTableNO, SIGNAL(textEdited(QString)), OrderSupervise, SLOT(OnDelta()));

        QMetaObject::connectSlotsByName(OrderSupervise);
    } // setupUi

    void retranslateUi(QDialog *OrderSupervise)
    {
        OrderSupervise->setWindowTitle(QApplication::translate("OrderSupervise", "\350\256\242\345\215\225\347\256\241\347\220\206", Q_NULLPTR));
        btnBack->setText(QString());
        btnNext->setText(QString());
        gbContent->setTitle(QApplication::translate("OrderSupervise", "\350\256\242\345\215\225\345\206\205\345\256\271", Q_NULLPTR));
        btnNLine->setText(QApplication::translate("OrderSupervise", "\346\267\273\345\212\240\350\217\234\345\223\201", Q_NULLPTR));
        btnDLine->setText(QApplication::translate("OrderSupervise", "\345\210\240\351\231\244\350\217\234\345\223\201", Q_NULLPTR));
        gbProperty->setTitle(QApplication::translate("OrderSupervise", "\350\256\242\345\215\225\345\261\236\346\200\247", Q_NULLPTR));
        leCustomer->setInputMask(QString());
        leCustomer->setText(QString());
        lblID->setText(QApplication::translate("OrderSupervise", "\350\256\242\345\215\225ID\357\274\232", Q_NULLPTR));
        lblName->setText(QApplication::translate("OrderSupervise", "\350\256\242\345\215\225\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        lblWaitorID->setText(QApplication::translate("OrderSupervise", "\346\234\215\345\212\241\345\221\230ID\357\274\232", Q_NULLPTR));
        lblCustomer->setText(QApplication::translate("OrderSupervise", "\347\224\250\346\210\267ID\357\274\232", Q_NULLPTR));
        lblTableNO->setText(QApplication::translate("OrderSupervise", "\346\241\214\345\217\267\357\274\232", Q_NULLPTR));
        btnSave->setText(QApplication::translate("OrderSupervise", "\344\277\235\345\255\230\346\224\271\345\212\250", Q_NULLPTR));
        btnUndo->setText(QApplication::translate("OrderSupervise", "\346\222\244\351\224\200\346\224\271\345\212\250", Q_NULLPTR));
        btnAdd->setText(QString());
        btnDel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OrderSupervise: public Ui_OrderSupervise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERSUPERVISE_H
