#include <QDesktopWidget>
#include <QDebug>

#include "ui_template_window.h"
#include "../headers/furniture.hpp"
#include "../headers/template_window.hpp"

TemplateWindow::TemplateWindow(QWidget *parent)
    : CenteredWindow(parent), ui(new Ui::TemplateWindow)
{
    ui->setupUi(this);

//    this->setStyleSheet("QToolTip { color: red; background-size: 0px;"
//                        "background-color: black; border: 1px solid black; }");
    setWindowCenter(1.25, 1.25);
    setWindowTitle("Home Planner 2D");

    drawGraphicsScene();
}

TemplateWindow::~TemplateWindow()
{
    delete ui;
}

void TemplateWindow::drawGraphicsScene()
{
    scene = new QGraphicsScene(this);
    /* screenWidth and screenHeight are inherited from CenteredWindow */
    scene->setSceneRect(0,0, screenWidth,screenHeight);

    Furniture *f1 = new Furniture;
    Furniture *f2 = new Furniture;

    scene->addItem(f1);
    scene->addItem(f2);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    scene->addText("Living room");
}

void TemplateWindow::on_btnDeleteItem_clicked()
{
    // TODO
}

void TemplateWindow::on_actionClear_All_triggered()
{
    ui->graphicsView->scene()->clear();
}

void TemplateWindow::on_actionQuit_triggered() {
    close();
}

void TemplateWindow::on_btnRotateSceneRight_clicked() {
    ui->graphicsView->rotate(5);
}

void TemplateWindow::on_btnRotateSceneLeft_clicked() {
    ui->graphicsView->rotate(-5);
}

void TemplateWindow::on_btnCenterScene_clicked() {
    ui->graphicsView->centerOn(screenWidth/2, screenHeight/2);
}

void TemplateWindow::on_btnZoomIn_clicked() {
    ui->graphicsView->scale(1.1, 1.1);
}

void TemplateWindow::on_btnZoomOut_clicked() {
    ui->graphicsView->scale(0.9, 0.9);
}
