#include "headers/main_menu_window.hpp"
#include "ui_main_menu_window.h"

#include <QDesktopWidget>
#include <QMessageBox>

MainMenuWindow::MainMenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuWindow)
{
    ui->setupUi(this);

    setWindowCenter(2.5, 1.5);
    setFixedSize(size());   // Main menu window is non-resizable
    setWindowTitle("Home Planner 2D");
    ui->stackedWidget->setCurrentIndex(0);
}

MainMenuWindow::~MainMenuWindow()
{
    delete ui;
}

void MainMenuWindow::setWindowCenter(double widthCoefficient, double heightCoefficient)
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
       after the setFixedSize() has been set. */
    setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    setMinimumSize(0, 0);

    ui->stackedWidget->resize(int(width), int(height));
    resize(int(width), int(height));
    setFixedSize(size());
    move(x, y);
}

void MainMenuWindow::on_btnQuit_clicked()
{
    close();
}

void MainMenuWindow::on_btnCreateNew_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    // Resizing the window to default size
    setWindowCenter(2, 1.75);
}

void MainMenuWindow::on_btnBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    // Making the window wider and shorter
    setWindowCenter(2.5, 1.5);
}

void MainMenuWindow::on_btnAbout_clicked()
{
    QMessageBox::about(this, "About Us",
       "This is a project done by Nevena Ajvaz and Nenad Ajvaz "
       "for a Software Development course.\n\nThis course is "
       "held at Computer Science department of Faculty of "
       "Mathematics, University of Belgrade, Serbia.");
}

void MainMenuWindow::on_btnInstructions_clicked()
{
     QMessageBox::about(this, "Instructions", "To be done...");
}
