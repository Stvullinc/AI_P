/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 450);
        MainWindow->setCursor(QCursor(Qt::CursorShape::UpArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        QFont font;
        font.setPointSize(13);
        textBrowser->setFont(font);
        textBrowser->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::UpArrowCursor)));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setFont(font);
        lineEdit->setCursor(QCursor(Qt::CursorShape::UpArrowCursor));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setCursor(QCursor(Qt::CursorShape::UpArrowCursor));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "AI-psychologyst", nullptr));
#if QT_CONFIG(tooltip)
        textBrowser->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        textBrowser->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"        QTextBrowser {\n"
"            border: 1px solid #D0D0D0; /* \320\241\320\262\320\265\321\202\320\273\320\276-\321\201\320\265\321\200\320\260\321\217 \321\200\320\260\320\274\320\272\320\260 */\n"
"            border-radius: 8px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"            padding: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 */\n"
"            background-color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\204\320\276\320\275 */\n"
"        }\n"
"       ", nullptr));
        lineEdit->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"          QLineEdit {\n"
"              border: 1px solid #D0D0D0; /* \320\241\320\262\320\265\321\202\320\273\320\276-\321\201\320\265\321\200\320\260\321\217 \321\200\320\260\320\274\320\272\320\260 */\n"
"              border-radius: 8px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"              padding: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 */\n"
"              background-color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\204\320\276\320\275 */\n"
"          }\n"
"          QLineEdit:focus {\n"
"              border: 1px solid #007AFF; /* \320\241\320\270\320\275\320\270\320\271 \321\206\320\262\320\265\321\202 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"          }\n"
"         ", nullptr));
        pushButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"          QPushButton {\n"
"              background-color: #007AFF; /* \320\241\320\270\320\275\320\270\320\271 \321\206\320\262\320\265\321\202 */\n"
"              color: white; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"              border-radius: 8px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"              padding: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 */\n"
"              font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #0051A8; /* \320\242\320\265\320\274\320\275\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"          }\n"
"          QPushButton:pre"
                        "ssed {\n"
"              background-color: #003D7A; /* \320\225\321\211\320\265 \321\202\320\265\320\274\320\275\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"          }\n"
"         ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
