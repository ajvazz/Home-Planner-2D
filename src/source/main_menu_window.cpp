#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QPainter>

#include "ui_main_menu_window.h"
#include "../headers/main_menu_window.hpp"

MainMenuWindow::MainMenuWindow(QWidget *parent)
    : CenteredWindow(parent), ui(new Ui::MainMenuWindow)
{
    ui->setupUi(this);

    /* Only main menu window is non-resizable */
    setWindowCenter(2.5, 1.5);
    setFixedSize(size());
    setBackgroundImage();
    ui->stackedWidget->setCurrentIndex(0);

    setWindowTitle("Home Planner 2D");
}

MainMenuWindow::~MainMenuWindow()
{
    delete ui;
}

void MainMenuWindow::setBackgroundImage()
{
    QPixmap background(":/img/blueprint_blue_1.jpg");

    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}

void MainMenuWindow::on_btnQuit_clicked()
{
    close();
}

void MainMenuWindow::on_btnCreateNew_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    setWindowCenter(2, 1.75);
    setFixedSize(size());
}

void MainMenuWindow::on_btnBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    setWindowCenter(2.5, 1.5);
    setFixedSize(size());
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

void MainMenuWindow::on_btnQt_clicked()
{
    QMessageBox::aboutQt(this);
}
