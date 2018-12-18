#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>

#include "ui_main_menu_window.h"
#include "../headers/main_menu_window.hpp"

MainMenuWindow::MainMenuWindow(QWidget *parent)
    : CenteredWindow(parent), ui(new Ui::MainMenuWindow)
{
    ui->setupUi(this);

    /* Resizing stacked widget proportionally to screen size */
    double width  = QApplication::desktop()->width()  / 2.5;
    double height = QApplication::desktop()->height() / 1.5;
    ui->stackedWidget->resize(int(width), int(height));
    ui->stackedWidget->setCurrentIndex(0);

    /* Only main menu window is non-resizable */
    setWindowCenter(2.5, 1.5);
    setFixedSize(size());

    setWindowTitle("Home Planner 2D");
}

MainMenuWindow::~MainMenuWindow()
{
    delete ui;
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

void MainMenuWindow::on_btnTemplate_clicked()
{
   tempWind = new TemplateWindow(this);
   hide();
   tempWind->show();
}

void MainMenuWindow::on_btnScratch_clicked()
{
    designWind = new DesignWindow();
    hide();
    designWind->show();
}
