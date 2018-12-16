#ifndef TEMPLATE_WINDOW_HPP
#define TEMPLATE_WINDOW_HPP

#include <QMainWindow>
#include <QGraphicsScene>

//#include "centered_window.hpp"

namespace Ui {
class TemplateWindow;
}

class TemplateWindow : public QMainWindow /*, public CenteredWindow */
{
    Q_OBJECT

public:
    explicit TemplateWindow(QWidget *parent = nullptr);
    ~TemplateWindow();

private slots:
    void on_actionQuit_triggered();

    void on_toolBox_currentChanged(int index);

private:
    Ui::TemplateWindow *ui;
    QGraphicsScene *scene;

    void drawGraphicsScene();
    void setWindowCenter(double widthCoefficient, double heightCoefficient);
};

#endif // TEMPLATE_WINDOW_HPP
