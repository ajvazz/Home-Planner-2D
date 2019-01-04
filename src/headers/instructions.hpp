#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include <QMainWindow>
#include "centered_window.hpp"

namespace Ui {
class Instructions;
}

class Instructions : public CenteredWindow /*QMainWindow*/
{
    Q_OBJECT

public:
    explicit Instructions(QWidget *parent = nullptr);
    ~Instructions();

private:
    Ui::Instructions *ui;
};

#endif // INSTRUCTIONS_HPP
