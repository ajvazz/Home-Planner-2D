#include <QApplication>
#include <QDesktopWidget>

#include "ui_design_window.h"
#include "../headers/design_window.hpp"

DesignWindow::DesignWindow(QWidget *parent)
    : CenteredWindow(parent), ui(new Ui::DesignWindow)
{
    ui->setupUi(this);
    setWindowCenter(1.25, 1.25);
}

DesignWindow::~DesignWindow()
{
    delete ui;
}
