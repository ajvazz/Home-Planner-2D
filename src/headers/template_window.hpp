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
    void on_actionQuit_triggered();
    void on_actionClearAll_triggered();

private:
    Ui::TemplateWindow *ui;
    QGraphicsScene *scene;

    void drawGraphicsScene();
};

#endif // TEMPLATE_WINDOW_HPP
