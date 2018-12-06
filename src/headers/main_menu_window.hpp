#ifndef MAIN_MENU_WINDOW_HPP
#define MAIN_MENU_WINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainMenuWindow;
}

class MainMenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuWindow(QWidget *parent = nullptr);
    ~MainMenuWindow();

private slots:
    void on_btnCreateNew_clicked();
    void on_btnInstructions_clicked();
    void on_btnAbout_clicked();
    void on_btnQuit_clicked();
    void on_btnBack_clicked();

private:
    Ui::MainMenuWindow *ui;
    void setWindowCenter(double widthCoefficient, double heightCoefficient);
};

#endif // MAIN_MENU_WINDOW_HPP
