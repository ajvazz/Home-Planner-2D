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
    scene->setSceneRect(-200, -200, 300, 300);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(600, 400);
}

void TemplateWindow::on_actionQuit_triggered()
{
    close();
}

void TemplateWindow::on_toolBox_currentChanged(int index)
{
    if(index == 0) {
        // TODO
    }
}
