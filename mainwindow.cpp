#include <chrono>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <thread>

#include <QAudioOutput>
#include <QCheckBox>
#include <QCoreApplication>
#include <QMediaPlayer>
#include <QUrl>

#include "mainwindow.h"
#include "ui_mainwindow.h"


QCheckBox *boxes[18][24];
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 24; j++) {
            QCheckBox *c = new QCheckBox(ui->centralwidget);
            c->setGeometry(j * 14, i * 14, 14, 14);
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
void MainWindow::play()
{
    std::ifstream text("E:\\Qt\\badapple.txt");
    std::string line;
    while (std::getline(text, line)) {
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 24; j++) {
                boxes[i][j]->setChecked(line[i * 24 + j] - '0');
                boxes[i][j]->update();
            }
        }
//        QCoreApplication::processEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
    }
    text.close();
}

void MainWindow::on_actionStart_triggered()
{
    std::thread playThread([this]() {
        this->play();
    });
    playThread.detach();

    QMediaPlayer* player = new QMediaPlayer;
    QAudioOutput* audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setSource(QUrl::fromLocalFile("E:\\Qt\\BadApple.mp3"));
    audioOutput->setVolume(50);
    player->play();
}
