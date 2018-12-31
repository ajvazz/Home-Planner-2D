#include <QApplication>
#include <QDesktopWidget>
#include <QInputDialog>
#include <QDebug>

#include "ui_design_window.h"
#include "../headers/design_window.hpp"
#include "../headers/room.hpp"

DesignWindow::DesignWindow(QWidget *parent)
    : CenteredWindow(parent), ui(new Ui::DesignWindow)
{
    ui->setupUi(this);
    setWindowCenter(1.25, 1.25);

    scene = new QGraphicsScene(this);
    /* screenWidth and screenHeight are inherited from CenteredWindow */
    scene->setSceneRect(0,0, screenWidth/1.5, screenHeight/1.5);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    /* Initial 'zoom' */
    ui->graphicsView->scale(1.25, 1.25);
}

DesignWindow::~DesignWindow()
{
    delete ui;
}

void DesignWindow::on_btnNewRoom_clicked()
{
    QString text = QInputDialog::getText(this,"Room dimesions",
        "Enter dimensions of your room in meters (width, height)");

    if (text.isEmpty())
        return;

    /* Parsing isn't foolproof */
    QStringList dimensions = text.split(",");
    int width  = dimensions.at(0).toInt();
    int height = dimensions.at(1).toInt();

    /* By our measurements, 1.5m equals 50px, hence 1m equals ~33px */
    Room *r = new Room(width*33, height*33);
    ui->graphicsView->scene()->addItem(r);
}
