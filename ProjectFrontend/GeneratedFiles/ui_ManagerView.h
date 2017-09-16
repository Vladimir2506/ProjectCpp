/********************************************************************************
** Form generated from reading UI file 'ManagerView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERVIEW_H
#define UI_MANAGERVIEW_H

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
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerView
{
public:
    QLabel *lblInfo;
    QGroupBox *gbCook;
    QTableView *tbCook;
    QComboBox *cbCook;
    QLabel *lblCook;
    QGroupBox *gbWaitor;
    QComboBox *cbWaitor;
    QLabel *lblWaitor;
    QTableView *tbWaitor;
    QTableView *tbComm;
    QLabel *lblComm;
    QPushButton *btnProfile;
    QPushButton *btnSeatVacance;
    QGroupBox *gbVolume;
    QTableWidget *tbVolume;
    QLabel *lblManagerBGN;

    void setupUi(QDialog *ManagerView)
    {
        if (ManagerView->objectName().isEmpty())
            ManagerView->setObjectName(QStringLiteral("ManagerView"));
        ManagerView->resize(1000, 900);
        ManagerView->setMinimumSize(QSize(1000, 900));
        ManagerView->setMaximumSize(QSize(1000, 900));
        lblInfo = new QLabel(ManagerView);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        lblInfo->setGeometry(QRect(25, 175, 375, 25));
        gbCook = new QGroupBox(ManagerView);
        gbCook->setObjectName(QStringLiteral("gbCook"));
        gbCook->setGeometry(QRect(25, 225, 450, 325));
        tbCook = new QTableView(gbCook);
        tbCook->setObjectName(QStringLiteral("tbCook"));
        tbCook->setGeometry(QRect(50, 100, 350, 200));
        tbCook->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbCook->setSelectionMode(QAbstractItemView::SingleSelection);
        cbCook = new QComboBox(gbCook);
        cbCook->setObjectName(QStringLiteral("cbCook"));
        cbCook->setGeometry(QRect(225, 50, 150, 25));
        lblCook = new QLabel(gbCook);
        lblCook->setObjectName(QStringLiteral("lblCook"));
        lblCook->setGeometry(QRect(50, 50, 150, 25));
        gbWaitor = new QGroupBox(ManagerView);
        gbWaitor->setObjectName(QStringLiteral("gbWaitor"));
        gbWaitor->setGeometry(QRect(525, 225, 450, 650));
        cbWaitor = new QComboBox(gbWaitor);
        cbWaitor->setObjectName(QStringLiteral("cbWaitor"));
        cbWaitor->setGeometry(QRect(225, 50, 150, 25));
        lblWaitor = new QLabel(gbWaitor);
        lblWaitor->setObjectName(QStringLiteral("lblWaitor"));
        lblWaitor->setGeometry(QRect(50, 50, 150, 25));
        tbWaitor = new QTableView(gbWaitor);
        tbWaitor->setObjectName(QStringLiteral("tbWaitor"));
        tbWaitor->setGeometry(QRect(50, 100, 350, 200));
        tbWaitor->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbWaitor->setSelectionMode(QAbstractItemView::SingleSelection);
        tbComm = new QTableView(gbWaitor);
        tbComm->setObjectName(QStringLiteral("tbComm"));
        tbComm->setGeometry(QRect(50, 350, 350, 275));
        tbComm->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbComm->setSelectionMode(QAbstractItemView::SingleSelection);
        lblComm = new QLabel(gbWaitor);
        lblComm->setObjectName(QStringLiteral("lblComm"));
        lblComm->setGeometry(QRect(150, 315, 150, 25));
        lblComm->setAlignment(Qt::AlignCenter);
        btnProfile = new QPushButton(ManagerView);
        btnProfile->setObjectName(QStringLiteral("btnProfile"));
        btnProfile->setGeometry(QRect(800, 175, 100, 40));
        btnSeatVacance = new QPushButton(ManagerView);
        btnSeatVacance->setObjectName(QStringLiteral("btnSeatVacance"));
        btnSeatVacance->setGeometry(QRect(650, 175, 125, 40));
        gbVolume = new QGroupBox(ManagerView);
        gbVolume->setObjectName(QStringLiteral("gbVolume"));
        gbVolume->setGeometry(QRect(25, 575, 450, 300));
        tbVolume = new QTableWidget(gbVolume);
        tbVolume->setObjectName(QStringLiteral("tbVolume"));
        tbVolume->setGeometry(QRect(50, 50, 350, 225));
        tbVolume->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbVolume->setSelectionMode(QAbstractItemView::SingleSelection);
        lblManagerBGN = new QLabel(ManagerView);
        lblManagerBGN->setObjectName(QStringLiteral("lblManagerBGN"));
        lblManagerBGN->setGeometry(QRect(0, 0, 1000, 900));
        lblManagerBGN->raise();
        lblInfo->raise();
        gbCook->raise();
        gbWaitor->raise();
        btnProfile->raise();
        btnSeatVacance->raise();
        gbVolume->raise();

        retranslateUi(ManagerView);
        QObject::connect(cbCook, SIGNAL(currentTextChanged(QString)), ManagerView, SLOT(BindCook(QString)));
        QObject::connect(cbWaitor, SIGNAL(currentTextChanged(QString)), ManagerView, SLOT(BindWaitor(QString)));
        QObject::connect(btnProfile, SIGNAL(clicked()), ManagerView, SLOT(OnProfile()));
        QObject::connect(btnSeatVacance, SIGNAL(clicked()), ManagerView, SLOT(OnSetTable()));

        QMetaObject::connectSlotsByName(ManagerView);
    } // setupUi

    void retranslateUi(QDialog *ManagerView)
    {
        ManagerView->setWindowTitle(QApplication::translate("ManagerView", "\351\244\220\345\216\205\347\273\217\347\220\206", Q_NULLPTR));
        lblInfo->setText(QString());
        gbCook->setTitle(QApplication::translate("ManagerView", "\345\216\250\345\270\210\345\267\245\344\275\234\346\203\205\345\206\265", Q_NULLPTR));
        lblCook->setText(QApplication::translate("ManagerView", "\350\257\267\351\200\211\346\213\251\344\270\200\345\220\215\345\216\250\345\270\210", Q_NULLPTR));
        gbWaitor->setTitle(QApplication::translate("ManagerView", "\346\234\215\345\212\241\345\221\230\345\267\245\344\275\234\346\203\205\345\206\265", Q_NULLPTR));
        lblWaitor->setText(QApplication::translate("ManagerView", "\350\257\267\351\200\211\346\213\251\344\270\200\345\220\215\346\234\215\345\212\241\345\221\230", Q_NULLPTR));
        lblComm->setText(QApplication::translate("ManagerView", "\350\257\245\346\234\215\345\212\241\345\221\230\350\216\267\345\276\227\347\232\204\350\257\204\344\273\267", Q_NULLPTR));
        btnProfile->setText(QApplication::translate("ManagerView", "\344\270\252\344\272\272\350\265\204\346\226\231", Q_NULLPTR));
        btnSeatVacance->setText(QApplication::translate("ManagerView", "\350\256\276\347\275\256\351\244\220\346\241\214\346\225\260", Q_NULLPTR));
        gbVolume->setTitle(QApplication::translate("ManagerView", "\350\217\234\345\223\201\351\224\200\351\207\217", Q_NULLPTR));
        lblManagerBGN->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ManagerView: public Ui_ManagerView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERVIEW_H
