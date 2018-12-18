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

private:
    Ui::CenteredWindow *ui;
};

#endif // CENTERED_WINDOW_HPP
