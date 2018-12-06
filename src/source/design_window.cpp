#include "headers/design_window.hpp"
#include "ui_design_window.h"

DesignWindow::DesignWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DesignWindow)
{
    ui->setupUi(this);
}

DesignWindow::~DesignWindow()
{
    delete ui;
}
