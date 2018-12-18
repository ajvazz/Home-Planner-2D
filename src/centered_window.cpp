#include "centered_window.hpp"
#include "ui_centered_window.h"

CenteredWindow::CenteredWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CenteredWindow)
{
    ui->setupUi(this);
}

CenteredWindow::~CenteredWindow()
{
    delete ui;
}
