#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir dir; //("C:/Users/Luis/Documents/Qt/QDirDemo");
//    if(dir.exists())
//        QMessageBox::information(this, "title", "true");
//    else
//        QMessageBox::information(this, "title", "false");
    foreach (QFileInfo var, dir.drives()) {
        ui->comboBox->addItem(var.absoluteFilePath());
    }

    QDir dir2("C:/Users/Luis/Documents/Qt/QDirDemo");
    foreach (QFileInfo var, dir2.entryInfoList()) {
        if (var.isDir())
            ui->listWidget->addItem("Dir : " + var.absoluteFilePath());
        if (var.isFile())
            ui->listWidget->addItem("File : " + var.absoluteFilePath());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDir dir("C:/Users/Luis/Documents/Qt/QDirDemo/yyy");
    if (dir.exists())
        QMessageBox::information(this, "title", "dir exists");
    else
        dir.mkpath("C:/Users/Luis/Documents/Qt/QDirDemo/yyy");
}
