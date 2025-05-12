#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "authwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void handleLoginSuccess();
    void handleRegisterSuccess();
    void appendToTextBrowser(const QString& label, const QString& message, const QString& color = "black");

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    AuthWidget *authWidget;
    QWidget *mainContent;

    QString ai_answer(QString question);
};

#endif // MAINWINDOW_H
