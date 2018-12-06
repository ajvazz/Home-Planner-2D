#ifndef TEMPLATE_WINDOW_HPP
#define TEMPLATE_WINDOW_HPP

#include <QMainWindow>

namespace Ui {
class TemplateWindow;
}

class TemplateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TemplateWindow(QWidget *parent = nullptr);
    ~TemplateWindow();

private:
    Ui::TemplateWindow *ui;
    void setWindowCenter(double widthCoefficient, double heightCoefficient);
};

#endif // TEMPLATE_WINDOW_HPP
