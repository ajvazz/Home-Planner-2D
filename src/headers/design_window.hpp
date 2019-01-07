#ifndef DESIGN_WINDOW_HPP
#define DESIGN_WINDOW_HPP

#include <QGraphicsScene>
#include <QKeyEvent>

#include "centered_window.hpp"
#include "template_window.hpp"

namespace Ui {
class DesignWindow;
}

class DesignWindow : public CenteredWindow
{
    Q_OBJECT

public:
    explicit DesignWindow(QWidget *parent = nullptr);
    ~DesignWindow() override;   // 'override' needed because of keypressevent
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::DesignWindow *ui;
    QGraphicsScene *scene;
    TemplateWindow *tempWind;

private slots:

    /* Menu bar options */
    void on_actionClear_All_triggered();
    void on_actionShortcuts_triggered();
    void on_actionQuit_triggered();
    void on_btnNext_clicked();

    /* Scene manipulation */
    void on_btnZoomOut_clicked();
    void on_btnZoomIn_clicked();
    void on_btnRotate_clicked();
    void on_btnDelete_clicked();
    void on_btnMoveUp_clicked();
    void on_btnMoveDown_clicked();
    void on_btnMoveRight_clicked();
    void on_btnMoveLeft_clicked();

    /* Floors & Tiles */
    void on_btnNewRoom_clicked();
    void on_btnTileWhite1_clicked();
    void on_btnTileWhite3_clicked();
    void on_btnTileWhite2_clicked();
    void on_btnTileBeige_clicked();
    void on_btnTileLightGrey1_clicked();
    void on_btnTileLightGrey2_clicked();
    void on_btnTileGrey_clicked();
    void on_btnFloorLight5_clicked();
    void on_btnFloorBeige_clicked();
    void on_btnFloorLight4_clicked();
    void on_btnFloorLight3_clicked();
    void on_btnFloorLight2_clicked();
    void on_btnFloorLight1_clicked();
    void on_btnFloorLight6_clicked();
    void on_btnFloorDark_clicked();
    void on_btnFloorGrey_clicked();
};

#endif // DESIGN_WINDOW_HPP
