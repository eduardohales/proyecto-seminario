#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Simulador.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startSimulationButton_clicked();
    void on_setVariablesButton_clicked();
    void on_selectFileButton_clicked();

private:
    Ui::MainWindow *ui;
    QString fullPath;
    int iteraciones;
};

#endif // MAINWINDOW_H
