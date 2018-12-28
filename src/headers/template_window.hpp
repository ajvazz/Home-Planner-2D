#ifndef TEMPLATE_WINDOW_HPP
#define TEMPLATE_WINDOW_HPP

#include <QGraphicsScene>
#include "centered_window.hpp"
#include "furniture.hpp"

namespace Ui {
class TemplateWindow;
}

class TemplateWindow : public CenteredWindow /*QMainWindow*/
{
    Q_OBJECT

public:
    explicit TemplateWindow(QWidget *parent = nullptr);
    ~TemplateWindow();

private slots:
    void on_actionClear_All_triggered();
    void on_actionQuit_triggered();

    /* Item manipulation */
    void on_btnDeleteItem_clicked();

    /* Scene manipulation */
    void on_btnZoomIn_clicked();
    void on_btnZoomOut_clicked();
    void on_btnCenterScene_clicked();
    void on_btnRotateSceneLeft_clicked();
    void on_btnRotateSceneRight_clicked();

    /* Buttons */
    void on_btnSofa1_Black_clicked();

private:
    Ui::TemplateWindow *ui;
    QGraphicsScene *scene;

    void drawGraphicsScene();
};

#endif // TEMPLATE_WINDOW_HPP
