#ifndef MAIN_MENU_WINDOW_HPP
#define MAIN_MENU_WINDOW_HPP

#include "centered_window.hpp"
#include "template_window.hpp"
#include "design_window.hpp"

namespace Ui {
class MainMenuWindow;
}

class MainMenuWindow : public CenteredWindow /*QMainWindow*/
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
    void on_btnTemplate_clicked();
    void on_btnScratch_clicked();

private:
    Ui::MainMenuWindow *ui;
    TemplateWindow *tempWind;
    DesignWindow *designWind;
};

#endif // MAIN_MENU_WINDOW_HPP
