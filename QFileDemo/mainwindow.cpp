#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file("C:/Users/Luis/Documents/Qt/QFileDemo/myfile.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text))
        QMessageBox::warning(this, "title", "file is not open");
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filter = "All files (*.*) ;; Text File (*.txt) ;; XML Files (*.xml)";
    QString filename = QFileDialog::getOpenFileName(this, "open a file", "C:/", filter);
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        QMessageBox::warning(this, "title", "file is not open");
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}
