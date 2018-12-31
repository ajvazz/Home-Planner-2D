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
       "Home Planner 2D is a university project created by Nenad Ajvaz and Nevena Ajvaz "
       "for a Software Development course.\n\nThis course is "
       "held at Computer Science department of Faculty of "
       "Mathematics, University of Belgrade in Serbia.");
}

void MainMenuWindow::on_btnInstructions_clicked()
{
    QMessageBox::about(this, "Instructions",
        "MAIN MENU\n\n"
        "Upon clicking 'Create New', the user is prompted with a choice between "
        "creating everything from the beginning or choosing a pre-made template.\n\n"

        "START FROM SCRATCH (not available yet)\n"
        ". . .\n\n"

        "CHOOSE A TEMPLATE\n\n"
        "(1) The right part of the working area is a sorted 'catalog' of furniture.\n"
        "(2) The left part of the working area is the current scheme and output, on which "
        "the user can interact with furniture.\n"
        "(3) On the bottom-left are the controls for that interaction.\n\n"

        "(1) Here the user can choose from a range of various pieces of furniture. "
        "For some hardly recognizable furniture, the user can hover over its icon for "
        "some short description. Items are created by clicking in the catalog and they "
        "will always appear in the center of the scheme.\n\n"

        "(2) This is the working area. Here the furniture will be created and manipulated "
        "with. Item and scene manipulation is under (3).\n"
        "When the item on is selected, a green outlined is shown. Multi selection is "
        "supported, which can be done in a standard way : CTRL + left click, and "
        "everything selected is treated as a single item.\n\n"

        "(3) Top row of buttons controls the scene, and the bottom row controls furniture."
        "Supported transformations are rotation, translation and zooming."
        "Hovering over control buttons will create a helpful bubble.\n\n"

        "List of shortcuts can be seen in menu bar or by clicking CTRL + S when the program starts.\n"
    );
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
