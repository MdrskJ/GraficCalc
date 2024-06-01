/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *g_label;
    QLabel *x_min_text;
    QLabel *x_max_text;
    QLabel *y_max_text;
    QLabel *y_min_text;
    QLineEdit *x_min_in;
    QLineEdit *x_max_in;
    QLineEdit *y_min_in;
    QLineEdit *y_max_in;
    QLineEdit *input_f_x;
    QLabel *name_f_x;
    QLineEdit *output_test;
    QLabel *name_output_test;
    QLineEdit *x_shag_in;
    QLabel *x_shag_text;
    QLabel *y_shag_text;
    QLineEdit *y_shag_in;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        g_label = new QLabel(centralwidget);
        g_label->setObjectName("g_label");
        g_label->setGeometry(QRect(0, 0, 825, 700));
        g_label->setStyleSheet(QString::fromUtf8("background: aqua;\n"
""));
        x_min_text = new QLabel(centralwidget);
        x_min_text->setObjectName("x_min_text");
        x_min_text->setGeometry(QRect(867, 132, 63, 20));
        x_max_text = new QLabel(centralwidget);
        x_max_text->setObjectName("x_max_text");
        x_max_text->setGeometry(QRect(867, 160, 63, 20));
        y_max_text = new QLabel(centralwidget);
        y_max_text->setObjectName("y_max_text");
        y_max_text->setGeometry(QRect(867, 221, 63, 20));
        y_min_text = new QLabel(centralwidget);
        y_min_text->setObjectName("y_min_text");
        y_min_text->setGeometry(QRect(867, 192, 63, 21));
        x_min_in = new QLineEdit(centralwidget);
        x_min_in->setObjectName("x_min_in");
        x_min_in->setGeometry(QRect(940, 127, 113, 28));
        x_max_in = new QLineEdit(centralwidget);
        x_max_in->setObjectName("x_max_in");
        x_max_in->setGeometry(QRect(940, 157, 113, 28));
        y_min_in = new QLineEdit(centralwidget);
        y_min_in->setObjectName("y_min_in");
        y_min_in->setGeometry(QRect(940, 187, 113, 28));
        y_max_in = new QLineEdit(centralwidget);
        y_max_in->setObjectName("y_max_in");
        y_max_in->setGeometry(QRect(940, 217, 113, 28));
        input_f_x = new QLineEdit(centralwidget);
        input_f_x->setObjectName("input_f_x");
        input_f_x->setGeometry(QRect(910, 68, 171, 28));
        name_f_x = new QLabel(centralwidget);
        name_f_x->setObjectName("name_f_x");
        name_f_x->setGeometry(QRect(844, 65, 63, 31));
        name_f_x->setLayoutDirection(Qt::LeftToRight);
        name_f_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        output_test = new QLineEdit(centralwidget);
        output_test->setObjectName("output_test");
        output_test->setGeometry(QRect(920, 387, 161, 28));
        name_output_test = new QLabel(centralwidget);
        name_output_test->setObjectName("name_output_test");
        name_output_test->setGeometry(QRect(850, 390, 63, 20));
        name_output_test->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        x_shag_in = new QLineEdit(centralwidget);
        x_shag_in->setObjectName("x_shag_in");
        x_shag_in->setGeometry(QRect(940, 260, 113, 28));
        x_shag_text = new QLabel(centralwidget);
        x_shag_text->setObjectName("x_shag_text");
        x_shag_text->setGeometry(QRect(867, 265, 63, 20));
        y_shag_text = new QLabel(centralwidget);
        y_shag_text->setObjectName("y_shag_text");
        y_shag_text->setGeometry(QRect(867, 293, 63, 20));
        y_shag_in = new QLineEdit(centralwidget);
        y_shag_in->setObjectName("y_shag_in");
        y_shag_in->setGeometry(QRect(940, 290, 113, 28));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        g_label->setText(QString());
        x_min_text->setText(QCoreApplication::translate("MainWindow", "min \320\277\320\276 X", nullptr));
        x_max_text->setText(QCoreApplication::translate("MainWindow", "max \320\277\320\276 X", nullptr));
        y_max_text->setText(QCoreApplication::translate("MainWindow", "max \320\277\320\276 Y", nullptr));
        y_min_text->setText(QCoreApplication::translate("MainWindow", "min \320\277\320\276 Y", nullptr));
        x_min_in->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
        x_max_in->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        y_min_in->setText(QCoreApplication::translate("MainWindow", "-9", nullptr));
        y_max_in->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        name_f_x->setText(QCoreApplication::translate("MainWindow", "f(x) = ", nullptr));
        name_output_test->setText(QCoreApplication::translate("MainWindow", "output:", nullptr));
        x_shag_in->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        x_shag_text->setText(QCoreApplication::translate("MainWindow", "\321\210\320\260\320\263 \320\277\320\276 X", nullptr));
        y_shag_text->setText(QCoreApplication::translate("MainWindow", "\321\210\320\260\320\263 \320\277\320\276 Y", nullptr));
        y_shag_in->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
