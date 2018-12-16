#include <QApplication>

#include "../headers/main_menu_window.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenuWindow w;
    w.show();

    return a.exec();
}
