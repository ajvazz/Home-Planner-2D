#include <QDesktopWidget>
#include <QDebug>

#include "ui_template_window.h"
#include "../headers/template_window.hpp"

TemplateWindow::TemplateWindow(QWidget *parent)
    : CenteredWindow(parent), ui(new Ui::TemplateWindow)
{
    ui->setupUi(this);

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
    scene->setSceneRect(0,0, 500,500);

    Furniture *f = new Furniture;
    scene->addItem(f);
    f->setFocus();

    ui->graphicsView->setScene(scene);
    scene->addText("Living room");

//    ui->graphicsView->resize(600, 400);
}

void TemplateWindow::on_actionQuit_triggered()
{
    close();
}

void TemplateWindow::on_actionClearAll_triggered()
{
    ui->graphicsView->scene()->clear();
}
