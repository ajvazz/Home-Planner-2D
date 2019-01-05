#include <QApplication>
#include <QDesktopWidget>
#include <QInputDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "ui_design_window.h"
#include "../headers/design_window.hpp"
#include "../headers/room.hpp"

DesignWindow::DesignWindow(QWidget *parent)
    : CenteredWindow(parent), ui(new Ui::DesignWindow)
{
    ui->setupUi(this);
    setWindowCenter(1.25, 1.25);
    setWindowTitle("Home Planner 2D");

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
        "Enter dimensions of your room in meters: (width, height)");

    if (text.isEmpty())
        return;

    /* This regex searches for two numbers separated by a comma, with
     * as many spaces in between. */
    QRegularExpression regex("\\d+\\s*,\\s*\\d+");
    QRegularExpressionMatch match = regex.match(text);
    bool hasMatch = match.hasMatch();

    /* If the input was not correct, return */
    if (hasMatch == false)
        return;

    QStringList dimensions = text.split(",");
    double width  = dimensions.at(0).toDouble();
    double height = dimensions.at(1).toDouble();

    /* By our measurements, 1.5m equals 50px, hence 1m equals ~33px */
    Room *r = new Room(width*33, height*33, "");
    ui->graphicsView->scene()->addItem(r);
}

void DesignWindow::on_btnNext_clicked()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Proceed to the next stage?",
        "Are you sure you want to send this room scheme for furniture equipment?",
        QMessageBox::No | QMessageBox::Yes);

    /* If the reply is yes, send data to TemplateWindow and hide DesignWindow */
    if (reply == QMessageBox::Yes) {

        QList<QGraphicsItem*> itemList = ui->graphicsView->scene()->items(Qt::AscendingOrder);

        tempWind = new TemplateWindow(this, itemList);
        DesignWindow::hide();
        tempWind->show();

    } else {
        return;
    }
}

/* Scene manipulation */

void DesignWindow::on_btnRotate_clicked()
{
    QList<QGraphicsItem*> selectedRooms = ui->graphicsView->scene()->selectedItems();
    if (selectedRooms.isEmpty())
        return;
    else {
        for (auto room : selectedRooms) {
            // if (item.type() == UserType+1)   produces error!
            Room *selectedRoom = qgraphicsitem_cast<Room*>(room);
            selectedRoom->rotate(-90);
        }
    }
}

void DesignWindow::on_btnZoomOut_clicked() {
    ui->graphicsView->scale(0.9, 0.9);
}

void DesignWindow::on_btnZoomIn_clicked() {
    ui->graphicsView->scale(1.1, 1.1);
}

void DesignWindow::on_btnDelete_clicked()
{
    QList<QGraphicsItem*> selectedRooms = ui->graphicsView->scene()->selectedItems();
    if (selectedRooms.isEmpty())
        return;
    else {
        for (auto room : selectedRooms) {
            // if (item.type() == UserType+1)   produces error!
            Room *selectedRoom = qgraphicsitem_cast<Room*>(room);
            delete selectedRoom;
        }
    }
}

void DesignWindow::on_btnMoveUp_clicked()
{
    QList<QGraphicsItem*> selectedRooms = ui->graphicsView->scene()->selectedItems();
    if (selectedRooms.isEmpty())
        return;
    else {
        for (auto room : selectedRooms) {
            Room *selectedRoom = qgraphicsitem_cast<Room*>(room);
            selectedRoom->moveBy(0,-0.75); // Up
        }
    }
}

void DesignWindow::on_btnMoveDown_clicked()
{
    QList<QGraphicsItem*> selectedRooms = ui->graphicsView->scene()->selectedItems();
    if (selectedRooms.isEmpty())
        return;
    else {
        for (auto room : selectedRooms) {
            Room *selectedRoom = qgraphicsitem_cast<Room*>(room);
            selectedRoom->moveBy(0,0.75); // Down
        }
    }
}

void DesignWindow::on_btnMoveRight_clicked()
{
    QList<QGraphicsItem*> selectedRooms = ui->graphicsView->scene()->selectedItems();
    if (selectedRooms.isEmpty())
        return;
    else {
        for (auto room : selectedRooms) {
            Room *selectedRoom = qgraphicsitem_cast<Room*>(room);
            selectedRoom->moveBy(0.75,0); // Right
        }
    }
}

void DesignWindow::on_btnMoveLeft_clicked()
{
    QList<QGraphicsItem*> selectedRooms = ui->graphicsView->scene()->selectedItems();
    if (selectedRooms.isEmpty())
        return;
    else {
        for (auto room : selectedRooms) {
            Room *selectedRoom = qgraphicsitem_cast<Room*>(room);
            selectedRoom->moveBy(-0.75,0); // Left
        }
    }
}

void DesignWindow::keyPressEvent(QKeyEvent *event)
{
    /*
     * +   zooms in  the scene
     * -   zooms out the scene
     * R   room rotate
     */

    switch ( event->key() )
    {
        case Qt::Key_Plus:
            ui->btnZoomIn->click();
            break;

        case Qt::Key_Minus:
            ui->btnZoomOut->click();
            break;

        case Qt::Key_R:
            ui->btnRotate->click();
            break;

        case Qt::Key_Delete:
            ui->btnDelete->click();
            break;

        case Qt::Key_N:
            ui->btnNewRoom->click();
            break;

        /* These don't work for some reason */
        case Qt::Key_Up:
            ui->btnMoveUp->click();
            break;
        case Qt::Key_Down:
            ui->btnMoveDown->click();
            break;
        case Qt::Key_Left:
            ui->btnMoveLeft->click();
            break;
        case Qt::Key_Right:
            ui->btnMoveRight->click();
            break;
    }
}

/* Menu bar options */

void DesignWindow::on_actionClear_All_triggered() {
    ui->graphicsView->scene()->clear();
}

void DesignWindow::on_actionShortcuts_triggered()
{
    QMessageBox::information(this, "Shortcuts",
        "SHORTCUT \t\t ACTION \n\n"
        "CTRL + H \t\t Opens this window \n"
        "CTRL + L \t\t Clears everything from the scene \n"
        "CTRL + Q \t\t Quits HomePlanner2D \n\n"

        "+/-"           "\t\t"  "Zoom in/out \n\n"

        "ROOMS (must be selected): \n"
        "R"        "\t\t"   "Rotate room(s) by 90 degrees \n"
        "Arrows [SHIFT]" "\t"   "Move room(s) [by 10px] \n"
        "DEL"           "\t\t"  "Delete room(s)"
    );
}

void DesignWindow::on_actionQuit_triggered() {
    DesignWindow::close();
}

/* FLOOR & TILES */

void DesignWindow::on_btnTileWhite1_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/tiles_white_1.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnTileWhite3_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/tiles_white_3.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnTileWhite2_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/tiles_white_2.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnTileBeige_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/tiles_beige.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnTileLightGrey1_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/tiles_light_grey.jpeg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnTileLightGrey2_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/tiles_lightgrey.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnTileGrey_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/tiles_grey.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnFloorLight5_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/floor_light_5.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnFloorBeige_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/floor_beige.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnFloorLight4_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/floor_light_4.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnFloorLight3_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/floor_light_3.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnFloorLight2_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/floor_light_2.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnFloorLight1_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/floor_light_1.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnFloorLight6_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/floor_light_6.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnFloorDark_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/floor_dark.jpg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}

void DesignWindow::on_btnFloorGrey_clicked()
{
    QList<QGraphicsItem*> selectedItems = ui->graphicsView->scene()->selectedItems();
    if (selectedItems.isEmpty())
        return;
    else {
        for (auto item : selectedItems) {
            Room *r = qgraphicsitem_cast<Room*>(item);
            r->setFloorPath(":/img/furniture/floor/floor_grey.jpeg");

            r->update();    // Immediately call paint() which redraws the room with new floor texture
        }
    } // if-else
}
