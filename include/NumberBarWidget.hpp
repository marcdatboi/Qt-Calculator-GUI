



#ifndef NUMBERBARWIDGET_HPP
#define NUMBERBARWIDGET_HPP

// Imports
#include <QApplication>
#include <QWidget>
#include <QLineEdit>


class NumberBarWidget : public QWidget {
    Q_OBJECT

    public:
        explicit NumberBarWidget(QWidget *parent = nullptr);
        ~NumberBarWidget();

        // Member functions
        QLineEdit* getLineEdit();
        void calculateEquation();

    private:

        // Field Members
        QLineEdit *inputField;
};
#endif