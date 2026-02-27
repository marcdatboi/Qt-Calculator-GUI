



#include "mainwindow.h"
//#include "uimainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    
    // 1. Set the window title
    setWindowTitle("My First Qt App");

    // 2. Create the button and give it a label
    myButton = new QPushButton("Click Me!", this);

    // 3. Position the button
    myButton->setGeometry(100, 100, 100, 30);

    // 4. THE CONNECTION: Link the click to our function
    connect(myButton, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
}

MainWindow::~MainWindow() {
    // Qt usually handles memory cleanup for children, 
    // so we leave this empty for now!
}

void MainWindow::handleButtonClick() {
    // Change the button text when clicked
    myButton->setText("Clicked!");
}
