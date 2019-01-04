#include "headers/instructions.hpp"
#include "ui_instructions.h"

Instructions::Instructions(QWidget *parent) :
    CenteredWindow(parent),
    ui(new Ui::Instructions)
{
    ui->setupUi(this);
    setWindowCenter(1.75, 1.5);
    setWindowTitle("Instructions");

    /* Start with the first tab opened */
    ui->tabWidget->setCurrentIndex(0);
}

Instructions::~Instructions()
{
    delete ui;
}
