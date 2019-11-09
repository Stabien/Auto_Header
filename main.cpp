#include <iostream>
#include <string>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include "main_window.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    mainWindow window;

    window.show();


    return (app.exec());
}
