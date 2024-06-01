#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QPixmap"
#include "QPainter"
#include "QPainterPath"
#include "QString"

#include "poland.h"


void drawAxes(double x_g_min, double x_g_max, double y_g_min, double y_g_max,
              double k_x, double k_y, double x_min, double y_max,
              double x_shag, double y_shag, QPainterPath &axe_path) {
    int ord_x = x_g_min + k_x * (0 - x_min);
    int abs_y = y_g_min + k_y * (0 - y_max);

    // рисуем ось y и стрелочку
    axe_path.moveTo(ord_x, y_g_max);
    axe_path.lineTo(ord_x, y_g_min);

    axe_path.lineTo(ord_x - 5, y_g_min + 5);
    axe_path.moveTo(ord_x, y_g_min);
    axe_path.lineTo(ord_x + 5, y_g_min + 5);

    // рисуем разметку оси y от начала координат вверх и вниз
    for (int y = y_shag; k_y * (y - y_max) > y_g_min + 10; y += y_shag) {
        axe_path.moveTo(ord_x - 5, k_y * (y - y_max));
        axe_path.lineTo(ord_x + 5, k_y * (y - y_max));
    }
    for (int y = -y_shag; k_y * (y - y_max) < y_g_max; y -= y_shag) {
        axe_path.moveTo(ord_x - 5, k_y * (y - y_max));
        axe_path.lineTo(ord_x + 5, k_y * (y - y_max));
    }

    // рисуем ось x и стрелочку
    axe_path.moveTo(x_g_min, abs_y);
    axe_path.lineTo(x_g_max, abs_y);

    axe_path.lineTo(x_g_max - 5, abs_y - 5);
    axe_path.moveTo(x_g_max, abs_y);
    axe_path.lineTo(x_g_max - 5, abs_y + 5);

    // рисуем разметку оси x от начала координат вправо и влево
    for (int x = x_shag; k_x * (x - x_min) < x_g_max - 10; x += x_shag) {
        axe_path.moveTo(k_x * (x - x_min), abs_y - 5);
        axe_path.lineTo(k_x * (x - x_min), abs_y + 5);
    }
    for (int x = -x_shag; k_x * (x - x_min) > 0; x -= x_shag) {
        axe_path.moveTo(k_x * (x - x_min), abs_y - 5);
        axe_path.lineTo(k_x * (x - x_min), abs_y + 5);
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    int W = 1100, H = 700;
    resize(W, H);

    btn = new QPushButton(this);
    btn->setObjectName("calc_btn");
    btn->setGeometry(W / 60 * 51, H / 20 * 18, W / 10, H / 20);
    btn->setText("build");
    btn->connect(btn, SIGNAL(clicked()), this, SLOT(my_click()));
    btn->setShortcut(Qt::Key_Return);

    ui->g_label->setGeometry(0, 0, W / 4 * 3, H);
    ui->g_label->setStyleSheet("background-color: white");

    // задаём оси
    QPixmap pm(ui->g_label->width(), ui->g_label->height());
    pm.fill(Qt::white);

    QPainter painter;
    painter.begin(&pm);

    QPainterPath path;
    path.moveTo(ui->g_label->width() / 2, 0);
    path.lineTo(ui->g_label->width() / 2, ui->g_label->height());
    path.moveTo(0, ui->g_label->height() / 2);
    path.lineTo(ui->g_label->width(), ui->g_label->height() / 2);

    painter.drawPath(path);
    ui->g_label->setPixmap(pm);
}


void MainWindow::my_click() {
    QString f_x = ui->input_f_x->text();

    const double Pi = 3.1415926535;

    QPixmap pm(ui->g_label->width(), ui->g_label->height());
    pm.fill(Qt::white);

    QPainter painter;
    painter.begin(&pm);

    QPainterPath g_path;
    QPainterPath axe_path;
    QPen g_pen(QColor("#1c51ed"), 2);
    QPen axe_pen(Qt::black, 1);

    double x_min = ui->x_min_in->text().toDouble();
    double x_max = ui->x_max_in->text().toDouble();
    double y_min = ui->y_min_in->text().toDouble();
    double y_max = ui->y_max_in->text().toDouble();
    double x_shag = ui->x_shag_in->text().toDouble();
    double y_shag = ui->y_shag_in->text().toDouble();

    int x_g_min = 0, x_g_max = pm.width();
    int y_g_min = 0, y_g_max = pm.height();

    double k_x = (x_g_max - x_g_min) / (x_max - x_min);
    double k_y = (y_g_min - y_g_max) / (y_max - y_min);

    double step = (x_max - x_min) / (2 * (x_g_max - x_g_min));
    double dx = step / 100;
    double y, y_dx, y_pr;
    double df, df_pr = 0;
    int x_g, y_g;

    bool flag_success = true;
    bool flag_continious = true;

    drawAxes(x_g_min, x_g_max, y_g_min, y_g_max, k_x, k_y, x_min, y_max, x_shag, y_shag, axe_path);


    for (double i = x_min; i <= x_max; i += step){
        double x = i;
        if (abs(i - trunc(i)) < step) x = trunc(i);

        QString temp_x = f_x, temp_dx = f_x;
        temp_x.replace("x", '(' + QString::number(x) + ')');
        temp_dx.replace("x", '(' + QString::number(x + dx) + ')');

        if (!calculate(temp_x.toStdString(), y) || isnan(y)) {
            // ui->input_f_x->setStyleSheet(" background-color: red; color: white ");
            // flag_success = false;
            flag_continious = false;
            continue;
        }

        x_g = x_g_min + k_x * (x - x_min);
        y_g = y_g_min + k_y * (y - y_max);

        if (!flag_continious) {
            flag_continious = true;
            g_path.moveTo(x_g, y_g);
            y_pr = y;
            ui->input_f_x->setStyleSheet(" background-color: #dadad9; color: black; ");
        }

        if (calculate(temp_dx.toStdString(), y_dx) && !isnan(y_dx) && x + dx < x_max) {
            calculate(temp_dx.toStdString(), y_dx);
            df = (y_dx - y) / dx;
            if (df * df_pr >= 0 && ((df + df_pr >= 0 && y - y_pr < 0) || (df + df_pr <= 0 && y - y_pr > 0))) {
                df_pr = df;
                y_pr = y;
                g_path.moveTo(x_g, y_g);
                continue;
            }
            df_pr = df;
            y_pr = y;
        }
        g_path.lineTo(x_g, y_g);
    }

    if (flag_success) {
        ui->output_test->setText("success!");
        ui->input_f_x->setStyleSheet(" background-color: #dadad9; color: black; ");
    }

    painter.setPen(axe_pen);
    painter.drawPath(axe_path);
    painter.setPen(g_pen);
    painter.drawPath(g_path);
    ui->g_label->setPixmap(pm);

}


MainWindow::~MainWindow() {
    delete ui;
}
