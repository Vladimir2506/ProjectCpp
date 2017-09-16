/********************************************************************************
** Form generated from reading UI file 'CookView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COOKVIEW_H
#define UI_COOKVIEW_H

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

class Ui_CookView
{
public:
    QLabel *lblInfo;
    QGroupBox *gbTodo;
    QListWidget *lstTodo;
    QPushButton *btnFinish;
    QLabel *lblTodo;
    QGroupBox *gbDone;
    QTableView *tbDone;
    QLabel *lblCookBGN;
    QPushButton *btnProfile;

    void setupUi(QDialog *CookView)
    {
        if (CookView->objectName().isEmpty())
            CookView->setObjectName(QStringLiteral("CookView"));
        CookView->resize(825, 750);
        CookView->setMinimumSize(QSize(825, 750));
        CookView->setMaximumSize(QSize(825, 750));
        lblInfo = new QLabel(CookView);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        lblInfo->setGeometry(QRect(25, 175, 275, 25));
        gbTodo = new QGroupBox(CookView);
        gbTodo->setObjectName(QStringLiteral("gbTodo"));
        gbTodo->setGeometry(QRect(25, 225, 400, 500));
        lstTodo = new QListWidget(gbTodo);
        lstTodo->setObjectName(QStringLiteral("lstTodo"));
        lstTodo->setGeometry(QRect(25, 75, 350, 350));
        lstTodo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lstTodo->setSelectionMode(QAbstractItemView::SingleSelection);
        lstTodo->setSelectionBehavior(QAbstractItemView::SelectItems);
        btnFinish = new QPushButton(gbTodo);
        btnFinish->setObjectName(QStringLiteral("btnFinish"));
        btnFinish->setGeometry(QRect(135, 440, 125, 40));
        lblTodo = new QLabel(gbTodo);
        lblTodo->setObjectName(QStringLiteral("lblTodo"));
        lblTodo->setGeometry(QRect(135, 40, 125, 25));
        lblTodo->setAlignment(Qt::AlignCenter);
        gbDone = new QGroupBox(CookView);
        gbDone->setObjectName(QStringLiteral("gbDone"));
        gbDone->setGeometry(QRect(450, 175, 350, 550));
        gbDone->setFocusPolicy(Qt::NoFocus);
        tbDone = new QTableView(gbDone);
        tbDone->setObjectName(QStringLiteral("tbDone"));
        tbDone->setGeometry(QRect(25, 25, 300, 500));
        tbDone->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbDone->setSelectionMode(QAbstractItemView::NoSelection);
        lblCookBGN = new QLabel(CookView);
        lblCookBGN->setObjectName(QStringLiteral("lblCookBGN"));
        lblCookBGN->setGeometry(QRect(0, 0, 825, 750));
        btnProfile = new QPushButton(CookView);
        btnProfile->setObjectName(QStringLiteral("btnProfile"));
        btnProfile->setGeometry(QRect(325, 175, 100, 40));
        lblCookBGN->raise();
        lblInfo->raise();
        gbTodo->raise();
        gbDone->raise();
        btnProfile->raise();

        retranslateUi(CookView);
        QObject::connect(lstTodo, SIGNAL(currentRowChanged(int)), CookView, SLOT(OnSelect(int)));
        QObject::connect(btnFinish, SIGNAL(clicked()), CookView, SLOT(CookOne()));
        QObject::connect(btnProfile, SIGNAL(clicked()), CookView, SLOT(OnProfile()));

        QMetaObject::connectSlotsByName(CookView);
    } // setupUi

    void retranslateUi(QDialog *CookView)
    {
        CookView->setWindowTitle(QApplication::translate("CookView", "\345\216\250\345\270\210", Q_NULLPTR));
        lblInfo->setText(QString());
        gbTodo->setTitle(QApplication::translate("CookView", "\345\276\205\347\203\271\351\245\252\347\232\204\350\217\234\345\223\201", Q_NULLPTR));
        btnFinish->setText(QApplication::translate("CookView", "\345\256\214\346\210\220\351\200\211\345\256\232\347\203\271\351\245\252", Q_NULLPTR));
        lblTodo->setText(QApplication::translate("CookView", "\345\210\206\351\205\215\347\232\204\350\217\234\345\223\201", Q_NULLPTR));
        gbDone->setTitle(QApplication::translate("CookView", "\345\267\262\345\256\214\346\210\220\347\232\204\350\217\234\345\223\201", Q_NULLPTR));
        lblCookBGN->setText(QString());
        btnProfile->setText(QApplication::translate("CookView", "\344\270\252\344\272\272\350\265\204\346\226\231", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CookView: public Ui_CookView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOKVIEW_H
