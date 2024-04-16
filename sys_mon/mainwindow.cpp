// mainwindow.cpp

#include "mainwindow.h"
#include "system_monitor.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a QTimer object
    timer = new QTimer(this);

    // Connect QTimer's timeout() signal to updateUsage() slot
    connect(timer, &QTimer::timeout, this, &MainWindow::updateUsage);

    // Start the timer to trigger every second
    timer->start(1000); // 1000 milliseconds = 1 second
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUsage() {
   SystemMonitor monitor;
   double cpu_usage = monitor.get_cpu_usage();
   double memory_usage = monitor.get_memory_usage();
   
   // Update CPU usage label
   ui->cpuLabel->setText(QString::number(cpu_usage) + "%");
   
   // Update memory usage label
   ui->memoryLabel->setText(QString::number(memory_usage) + "%");

}
