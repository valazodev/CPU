#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "../include/cpu/cpu.hpp"

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
    void on_spinnerA_valueChanged(int valor);
    void on_spinnerB_valueChanged(int valor);
    void on_lista_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;
    Cpu *cpu;
    void actualizarL();
    void actualizarH();
    void actualizarC();
};

#endif // MAINWINDOW_H
