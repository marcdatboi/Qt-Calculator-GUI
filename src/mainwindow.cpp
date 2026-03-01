



#include <QWidget>
#include <QMainWindow>
#include "mainwindow.h"
#include "NumberBarWidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    
    setWindowTitle("Calculator GUI");

    // Show the number display widget
    NumberBarWidget *calculatorDisplayWidget = new NumberBarWidget(this);
    setCentralWidget(calculatorDisplayWidget);
}

MainWindow::~MainWindow() {}
