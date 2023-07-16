#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>

QCheckBox *boxes[18][24];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 24; j++) {
            QCheckBox *c = new QCheckBox(ui->centralwidget);
            c->setGeometry(j * 16, i * 16, 16, 16);
            boxes[i][j] = c;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSelectAll_triggered()
{
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 24; j++) {
            boxes[i][j]->setChecked(true);
        }
    }
}

void MainWindow::on_actionUnselectAll_triggered()
{
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 24; j++) {
            boxes[i][j]->setChecked(false);
        }
    }
}

int fps = 15;

void MainWindow::on_actionStart_triggered()
{
    // 载入 E:\\Qt\\badapple.txt 并开始播放，1=选中，0=未选中，每行一帧
}

