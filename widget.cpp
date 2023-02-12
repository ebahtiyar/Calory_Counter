#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    p1.setWeigth(ui->weigth_spinBox->value());
    m_time = ui->time_spinBox->value();
    m_speed = ui->speed_spinBox->value();

    connect(ui->weigth_spinBox,&QDoubleSpinBox::valueChanged,
            this,&Widget::weigth_changed);
    connect(ui->time_spinBox,&QDoubleSpinBox::valueChanged,
            this,&Widget::time_changed);
    connect(ui->speed_spinBox,&QDoubleSpinBox::valueChanged,
            this,&Widget::speed_changed);

    connect(this,&Widget::calory_count_changed,[=](){
        ui->calory_label->setText(QString::number(m_calory_count));
    });

    calculate_calory();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculate_calory()
{
    m_calory_count = ( (0.0215 * (m_speed * m_speed * m_speed)) - (0.1765 * (m_speed * m_speed))
                            +(0.8710 * m_speed) + 1.4577) * p1.weigth() * m_time;
    emit calory_count_changed();
}

void Widget::weigth_changed(double weigth)
{
    p1.setWeigth(weigth);
    calculate_calory();
}

void Widget::time_changed(double time)
{
    m_time = time;
    calculate_calory();
}

void Widget::speed_changed(double speed)
{
    m_speed = speed;
    calculate_calory();
}


