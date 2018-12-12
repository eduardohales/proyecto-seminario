#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Simulador.h"
#include "Grafo.h"
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

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

// Comenzar la simulacion
void MainWindow::on_startSimulationButton_clicked()
{
    Grafo grafo;
    grafo.loadNetwork(this->fullPath.toStdString());
    grafo.printRoute();
    Simulador simulador;
    simulador.setGrafo(&grafo);
    simulador.setIteraciones(this->iteraciones);
    simulador.start();
}

// Abrir archivo de rutas en el explorador
void MainWindow::on_selectFileButton_clicked()
{
    this->fullPath = QFileDialog::getOpenFileName(this, tr("Open File"), ".", "Routes (*.rut)");
    QFileInfo fp(fullPath);
    QString fileName = fp.fileName();
    ui->fileNameLine->setText(fileName);

}

void MainWindow::on_setVariablesButton_clicked()
{
    QString tasaArribo = ui->TasaArriboLine->text();
    QString tasaSalida = ui->TasaSalidaLine->text();
    QString cargaTrafico = ui->CargaTraficoLine->text();
    QString Ton = ui->TonLine->text();
    QString Toff = ui->ToffLine->text();
    this->iteraciones = ui->iteracionesLine->text().toInt();

    std::cout << "tasa arribo: " << tasaArribo.toDouble() << std::endl;
    std::cout << "tasa salida: " << tasaSalida.toDouble() << std::endl;
    std::cout << "carga trafico: " << cargaTrafico.toDouble() << std::endl;
    std::cout << "Ton: " << Ton.toDouble() << std::endl;
    std::cout << "Toff: " << Toff.toDouble() << std::endl;

}
