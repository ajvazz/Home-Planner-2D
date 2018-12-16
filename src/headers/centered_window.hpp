#ifndef CENTERED_WINDOW_HPP
#define CENTERED_WINDOW_HPP

#include <QMainWindow>

class CenteredWindow : public QMainWindow
{
    Q_OBJECT
// Is this needed?
public:
    explicit CenteredWindow(QWidget *parent = nullptr);

protected:
    void setWindowCenter(double widthCoefficient, double heightCoefficient);
};

#endif // CENTERED_WINDOW_HPP
