#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
	ui(new Ui::MainWindow) {
    ui->setupUi(this);
    cpu = new Cpu;
    ui->outputC->setNum( 0 );
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_spinnerA_valueChanged(int valor) {
    cpu->actualizarAdec(valor);
    cpu->actualizar();
    ui->lcdA7->display( cpu->Ai(0) );
    ui->lcdA6->display( cpu->Ai(1) );
    ui->lcdA5->display( cpu->Ai(2) );
    ui->lcdA4->display( cpu->Ai(3) );
    ui->lcdA3->display( cpu->Ai(4) );
    ui->lcdA2->display( cpu->Ai(5) );
    ui->lcdA1->display( cpu->Ai(6) );
    ui->lcdA0->display( cpu->Ai(7) );
    actualizarL();
    actualizarH();
    actualizarC();
    ui->outputC->setNum( cpu->leerCdec() );
}

void MainWindow::on_spinnerB_valueChanged(int valor) {
    cpu->actualizarBdec(valor);
    cpu->actualizar();
    ui->lcdB7->display( cpu->Bi(0) );
    ui->lcdB6->display( cpu->Bi(1) );
    ui->lcdB5->display( cpu->Bi(2) );
    ui->lcdB4->display( cpu->Bi(3) );
    ui->lcdB3->display( cpu->Bi(4) );
    ui->lcdB2->display( cpu->Bi(5) );
    ui->lcdB1->display( cpu->Bi(6) );
    ui->lcdB0->display( cpu->Bi(7) );
    actualizarL();
    actualizarH();
    actualizarC();
    ui->outputC->setNum( cpu->leerCdec() );
}

void MainWindow::actualizarL() {
    ui->lcdL7->display( cpu->Li(0) );
    ui->lcdL6->display( cpu->Li(1) );
    ui->lcdL5->display( cpu->Li(2) );
    ui->lcdL4->display( cpu->Li(3) );
    ui->lcdL3->display( cpu->Li(4) );
    ui->lcdL2->display( cpu->Li(5) );
    ui->lcdL1->display( cpu->Li(6) );
    ui->lcdL0->display( cpu->Li(7) );
}

void MainWindow::actualizarH() {
    ui->lcdH7->display( cpu->Hi(0) );
    ui->lcdH6->display( cpu->Hi(1) );
    ui->lcdH5->display( cpu->Hi(2) );
    ui->lcdH4->display( cpu->Hi(3) );
    ui->lcdH3->display( cpu->Hi(4) );
    ui->lcdH2->display( cpu->Hi(5) );
    ui->lcdH1->display( cpu->Hi(6) );
    ui->lcdH0->display( cpu->Hi(7) );
}

void MainWindow::actualizarC() {
    ui->lcdC->display( cpu->C() );
}

void MainWindow::on_lista_currentRowChanged(int currentRow)
{
    cpu->actualizarSdec(currentRow);
    cpu->actualizar();
    ui->lcdS2->display( cpu->Si(0) );
    ui->lcdS1->display( cpu->Si(1) );
    ui->lcdS0->display( cpu->Si(2) );
    actualizarL();
    actualizarH();
    actualizarC();
    ui->outputC->setNum( cpu->leerCdec() );
}
