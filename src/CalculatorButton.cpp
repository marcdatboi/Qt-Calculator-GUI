



// Imports
#include <QWidget>
#include <QLineEdit>
#include <QDebug>
#include "CalculatorButton.hpp"

CalculatorButton::CalculatorButton
(
    QChar _displayNum,
    NumberBarWidget *_numberBarWidget,
    QWidget *_parent
)
    : displayNum(_displayNum)
    , numberBarWidget(_numberBarWidget)
    , QPushButton(_displayNum, _parent)
{

    // Shape & Font size
    this->setMinimumSize(100, 100);
    QFont font = this->font();
    font.setPointSize(20);

    this->setFont(font);

}

QChar CalculatorButton::getName() { return this->displayNum; }
int CalculatorButton::getValue() { return this->displayNum.digitValue(); }
void CalculatorButton::deleteErrorMsg() {
    if (this->numberBarWidget->getLineEdit()->text() == "ERROR") {
        this->numberBarWidget->getLineEdit()->clear();
    }

}

void CalculatorButton::insertToLineEdit() { // Yes, it inserts a QChar dtype :P

    const QList<QChar> specialChars = {'C', '<', '=', '('};
    // Special Chars: C, <, =, (

    switch (this->displayNum.unicode()) {

        case 'C': // Clears the expression
            this->numberBarWidget->getLineEdit()->clear();
            break;

        case '<': // Deletes the first char
            deleteErrorMsg();
            this->numberBarWidget->getLineEdit()->backspace();
            break;

        case '(': // Inserts parenthesis and moves the cursor inside the pair
            deleteErrorMsg();

            this->numberBarWidget->getLineEdit()->insert("()");
            this->numberBarWidget->getLineEdit()->setCursorPosition(this->numberBarWidget->getLineEdit()->text().length() - 1);
            break;

        case '=': // Calculates the result (says "ERROR" when a syntax error occurs)
            deleteErrorMsg();
            this->numberBarWidget->calculateEquation();
            break;

        default:
            deleteErrorMsg();
            this->numberBarWidget->getLineEdit()->insert(this->displayNum);
    }


}
