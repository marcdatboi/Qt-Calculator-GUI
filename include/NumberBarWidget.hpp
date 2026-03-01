



#ifndef NUMBERBARWIDGET_HPP
#define NUMBERBARWIDGET_HPP

// Imports
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QList>

class NumberBarWidget : public QWidget {
    Q_OBJECT

    public:
        explicit NumberBarWidget(QWidget *parent = nullptr);
        ~NumberBarWidget();

        // Member functions
        QLineEdit* getLineEdit();

    private:

        // Field Members
        QLineEdit *inputField;
};
#endif