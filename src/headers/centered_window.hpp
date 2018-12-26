#ifndef CENTERED_WINDOW_HPP
#define CENTERED_WINDOW_HPP

#include <QMainWindow>

namespace Ui {
class CenteredWindow;
}

class CenteredWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CenteredWindow(QWidget *parent = nullptr);
    ~CenteredWindow();
    void setWindowCenter(double widthCoefficient, double heightCoefficient);

    int screenWidth;
    int screenHeight;

private:
    Ui::CenteredWindow *ui;
};

#endif // CENTERED_WINDOW_HPP
