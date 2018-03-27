#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/Ava and me.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->statusBar->addPermanentWidget(ui->label_3);
    ui->statusBar->addPermanentWidget(ui->progressBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "test" && password == "test") {
        //QMessageBox::information(this, "Login", "Correct");
        //hide();
        //secDialog = new SecDialog(this);
        //secDialog->show();
        ui->statusBar->showMessage("Correct", 5000);
        ui->label_3->setText("Correct");
    }
    else {
        //QMessageBox::warning(this, "Login", "Incorrect");
        ui->statusBar->showMessage("Incorrect", 5000);
        ui->label_3->setText("Incorrect");
    }
}
