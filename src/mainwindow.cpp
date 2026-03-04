



#include <QWidget>
#include <QMainWindow>
#include <QLayout>
#include <QGridLayout>
#include <iostream>
#include "mainwindow.h"
#include "NumberBarWidget.hpp"
#include "CalculatorButton.hpp"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{

    setWindowTitle("Calculator GUI");
    setMinimumSize(720, 1000);
    setMaximumSize(1920, 1080);
    this->setStyleSheet(R"(
        QMainWindow: { background-color: #000000; }
    )");

    QWidget *centralWidget = new QWidget(this);
    QGridLayout *mainLayout = new QGridLayout(centralWidget);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(mainLayout);

    // Show the number display widget
    NumberBarWidget *calculatorDisplayWidget = new NumberBarWidget(this);
    mainLayout->addWidget(calculatorDisplayWidget, 1, 0);
    mainLayout->setRowStretch(0, 1);

    // Calculator Buttons 0-9
    QWidget *calculatorGridWidget = new QWidget(this);
    QGridLayout *calculatorButtonLayout = new QGridLayout(calculatorGridWidget);
    calculatorGridWidget->setLayout(calculatorButtonLayout);
    initializeButtons(mainLayout, calculatorGridWidget, calculatorButtonLayout, calculatorDisplayWidget);

}

void MainWindow::initializeButtons
(
    QLayout *universalLayout,
    QWidget *baseWidget,
    QGridLayout *layout,
    NumberBarWidget *numberBarWidget
)
{



    // #### CALCULATOR NUMBER BUTTONS ####

    // Spacing and stretches
    layout->setHorizontalSpacing(5);
    layout->setVerticalSpacing(5);
    //layout->setRowStretch(5, 1);
    universalLayout->addWidget(baseWidget); // Add widget to main layout

    QMap<QChar, QList<int>> allChars = { // Operator, Position (row, col)

        // Numbers
        {'1', {1, 0}},
        {'2', {1, 1}},
        {'3', {1, 2}},
        {'4', {2, 0}},
        {'5', {2, 1}},
        {'6', {2, 2}},
        {'7', {3, 0}},
        {'8', {3, 1}},
        {'9', {3, 2}},
        {'0', {4, 1}},

        // Arithmetic operators
        {'+', {3, 3}},
        {'-', {2, 3}},
        {'*', {1, 3}},
        {'/', {0, 3}},
        {'^', {0, 2}},
        {'(', {4, 0}},

        // Misc Operators
        {'<', {0, 1}},
        {'=', {4, 3}},
        {'C', {0, 0}},
        {'.', {4, 2}}
    };
    size_t totalChars = allChars.size();

    // Append all map items to a button obj
    int index = 0;
    QList<CalculatorButton*> allButtons;
    for (auto i = allChars.constBegin(); i != allChars.constEnd(); ++i) {

        // Coloring Numbers
        if (i.key().isDigit()) {
            allButtons.append
            (
                new CalculatorButton
                (
                    i.key(),
                    numberBarWidget,
                    baseWidget
                )
            );
            allButtons[index]->setStyleSheet(R"(
                QPushButton { background-color: #373737; }
                QPushButton:hover { background-color: #3F3F4E; }
                QPushButton:pressed { background-color: #41424C; }
            )");
        }
        else { // Color button gray
            allButtons.append
            (
                new CalculatorButton
                (
                    i.key(),
                    numberBarWidget,
                    baseWidget
                )
            );
            allButtons[index]->setStyleSheet(R"(
                QPushButton { background-color: #3F3F4E; }
                QPushButton:hover { background-color: #373737; }
                QPushButton:pressed { background-color: #41424C; }
            )");
        }
        index++;

    }
    /*
        **** KEY
        '<' -> Delete 1 number
        '=' -> Calculate total
        'C' -> Clear

        '+' -> Addition
        '-' -> Subtraction
        '*' -> Multiplication
        '/' -> Division
    */

    // Map Each button to the layout and mapping functions
    index = 0;
    for (auto i = allChars.constBegin(); i != allChars.constEnd(); ++i) {
        layout->addWidget(allButtons[index], i.value()[0], i.value()[1]); // Add to grid
        connect(allButtons[index], &CalculatorButton::clicked, allButtons[index], &CalculatorButton::insertToLineEdit);
        index++;
    }
}

MainWindow::~MainWindow() {}
