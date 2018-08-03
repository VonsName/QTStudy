#include "paintevent01.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaintEvent01 w;
    w.show();

    return a.exec();
}
