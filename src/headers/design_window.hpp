#ifndef DESIGN_WINDOW_HPP
#define DESIGN_WINDOW_HPP

#include <QGraphicsScene>

#include "centered_window.hpp"

namespace Ui {
class DesignWindow;
}

class DesignWindow : public CenteredWindow
{
    Q_OBJECT

public:
    explicit DesignWindow(QWidget *parent = nullptr);
    ~DesignWindow();

private slots:
    void on_btnNewRoom_clicked();

private:
    Ui::DesignWindow *ui;
    QGraphicsScene *scene;
};

#endif // DESIGN_WINDOW_HPP
