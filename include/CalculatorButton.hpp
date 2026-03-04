



// Imports
#include <QWidget>
#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include "NumberBarWidget.hpp"

class CalculatorButton : public QPushButton {
    Q_OBJECT

public:
    CalculatorButton
    (
        QChar _displayNum,
        NumberBarWidget *_numberBarWidget,
        QWidget *_parent = nullptr
    );

    QChar getName();
    int getValue();
    void deleteErrorMsg();

public slots:
    void insertToLineEdit();

private:
    QChar displayNum;
    NumberBarWidget *numberBarWidget;

};
