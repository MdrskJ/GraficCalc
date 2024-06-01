#include "mainwindow.h"

#include <QApplication>
#include <QFile>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QFile file_css(":/style.css");
    file_css.open(QFile::ReadOnly);
    a.setStyleSheet(file_css.readAll());

    MainWindow w;
    w.show();
    return a.exec();
}
