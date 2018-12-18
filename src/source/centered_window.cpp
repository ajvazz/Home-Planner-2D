#include <QApplication>
#include <QDesktopWidget>

#include "../headers/centered_window.hpp"
#include "ui_centered_window.h"

CenteredWindow::CenteredWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CenteredWindow)
{
    ui->setupUi(this);
}

CenteredWindow::~CenteredWindow()
{
    delete ui;
}

void CenteredWindow::setWindowCenter(double widthCoefficient, double heightCoefficient)
{
    /*
     * Code for window centering partly used from:
     * http://zetcode.com/gui/qt4/firstprograms/
     */
    int screenWidth  = QApplication::desktop()->width();
    int screenHeight = QApplication::desktop()->height();

    // i.e. height = 650, width = 500
    double width  = screenWidth / widthCoefficient;
    double height = screenHeight / heightCoefficient;

    int x = (screenWidth - int(width)) / 2;
    int y = (screenHeight - int(height)) / 2;

    /* These two lines are required if the window needs to be resized
       after the setFixedSize() has been set. Needed because of MainMenuWindow. */
    setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    setMinimumSize(0, 0);

    resize(int(width), int(height));
    move(x, y);
}
