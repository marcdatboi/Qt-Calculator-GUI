



#include <QVBoxLayout>
#include <QLineEdit>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QJSEngine>
#include "NumberBarWidget.hpp"

NumberBarWidget::NumberBarWidget(QWidget *parent) : QWidget(parent) {
    /*
        **** OVERVIEW:
                * This class displays and controls the dimensions of the calculator's
                display panel for showing all the numbers.

        **** FEATURES:
                * Automatically changes size when window changes dimensions
                * Aligned with the top-right of the window
                * Only allows numbers and arithmetic operators like /, -, *, +
    */
    QVBoxLayout *layout = new QVBoxLayout(this); // Stopping widgets from not resizing when the window dim's change

    // Calculator number input widget
    this->inputField = new QLineEdit(this); // Allow use to type stuff

    // Align to be top right so it can expand to the left when fullscreen
    layout->addWidget(inputField, 0, Qt::AlignTop);
    this->inputField->setAlignment(Qt::AlignRight);


    // Set font and placeholder text
    this->inputField->setStyleSheet(R"(
        QLineEdit {
            font-size: 100px;
        }
    )");
    this->inputField->setPlaceholderText("0");
    

    // Display Dimensions
    this->inputField->setFixedHeight(250);
    this->inputField->setMaximumWidth(1920);
    
    // Ensure the user does not type any unwanted characters
    QRegularExpression re("^[0-9\\+\\-\\*/\\^\\(\\)\\.]*$"); // Allow nums 0-9 and + - / * ( ) .
    auto *validator = new QRegularExpressionValidator(re, this);
    this->inputField->setValidator(validator);
}

// Member Functions
QLineEdit* NumberBarWidget::getLineEdit() { return this->inputField; }

void NumberBarWidget::calculateEquation() {
    // Calculates the equation within the QLineEdit object

    if (this->inputField->size().isEmpty()) return;

    QJSEngine engine;
    QString equation = this->inputField->text();
    QJSValue result = engine.evaluate(equation);

    result.isError() ?
    this->inputField->setText("ERROR") : // Replace the line with "ERROR"
    this->inputField->setText(result.toString()); // Replace the line with the result
}

NumberBarWidget::~NumberBarWidget() {}
