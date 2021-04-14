#include "widget.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    w.setGeometry(760, 390, 400, 300);
    w.show();

    return a.exec();
}
