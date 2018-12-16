#include <QDesktopWidget>
#include <QDebug>

#include "ui_template_window.h"
#include "../headers/template_window.hpp"

TemplateWindow::TemplateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TemplateWindow)
{
    ui->setupUi(this);
    setWindowCenter(1.25, 1.25);
    setWindowTitle("Home Planner 2D");

    drawGraphicsScene();
//    createList();
}

TemplateWindow::~TemplateWindow()
{
    delete ui;
}

void TemplateWindow::drawGraphicsScene()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-200, -200, 300, 300);
    ui->graphicsView->setScene(scene);
//    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->graphicsView->resize(600, 400);
//    qDebug() << ui->graphicsView->height();
//    qDebug() << ui->graphicsView->width();
}

void TemplateWindow::setWindowCenter(double widthCoefficient, double heightCoefficient)
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

    resize(int(width), int(height));
    move(x, y);
}

void TemplateWindow::on_actionQuit_triggered()
{
    close();
}

void TemplateWindow::on_toolBox_currentChanged(int index)
{
    if(index == 0) {

    }
}
