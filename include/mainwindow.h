



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLayout>
#include "NumberBarWidget.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:

        // Member Functions
    void initializeButtons
    (
        QLayout *universalLayout,
        QWidget *baseWidget,
        QGridLayout *layout,
        NumberBarWidget *numberBarWidget
    );
};

#endif // MAINWINDOW_H
