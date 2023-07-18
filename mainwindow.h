#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSelectAll_triggered();

    void on_actionUnselectAll_triggered();

    void on_actionStart_triggered();

private:
    Ui::MainWindow *ui;
    void play();
};
#endif // MAINWINDOW_H
