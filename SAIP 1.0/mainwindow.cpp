#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QUrl>
#include <QDesktopServices>
#include <cstdlib>

QString ai_answer(QString question)
{
    QString phrases[8] = {
        "ты справишься с этим!",
        "не сдавайся, ты на правильном пути!",
        "каждый день — это новый шанс!",
        "ты сильнее, чем думаешь!",
        "успех — это результат упорства!",
        "ты можешь достичь всего, что задумал!",
        "не бойся ошибок, они — часть пути!",
        "ты уникален и способен на многое!"
    };
    int rmin=0,rmax=8;
    int a = ((double) rand() / RAND_MAX) * (rmax - rmin)+ rmin;
    return phrases[a];
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendToTextBrowser(const QString& label, const QString& message, const QString& color) {
    QString formattedMessage = QString("<b>%1</b> %2").arg(label).arg(message);
    if (color != "black") {
        formattedMessage = QString("<font color='%1'>%2</font>").arg(color).arg(formattedMessage);
    }
    ui->textBrowser->append(formattedMessage);
}


void MainWindow::on_pushButton_clicked()
{
    QString question = ui->lineEdit->text();
    appendToTextBrowser("You:", question);

    QString answer = ai_answer(question);
    appendToTextBrowser("AI:", answer, "blue");
    ui->lineEdit->clear();
}

/*void MainWindow::on_pushButton_clicked()
{
    QString question = ui->lineEdit->text();
    ui->textBrowser->append("You: ");
    ui->textBrowser->append(question);
    ui->textBrowser->append("\n");
    ui->textBrowser->append("AI: ");
    ui->textBrowser->append(ai_answer(question));
    ui->textBrowser->append("\n");
}*/
void MainWindow::on_textBrowser_anchorClicked(const QUrl &url)
{
    QDesktopServices::openUrl(url);
}
