#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->label_test->setFont(font);
        QString string = font.toString();
        string.prepend("QFont(\"");
        string.append("\")");
        ui->lineEdit->setText(string);
    }
}

void Widget::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor(Qt::gray,this,"text color",QColorDialog::ShowAlphaChannel);
    QString string = QString("\"color: rgb(%1, %2, %3);\"").arg(color.red()).arg(color.green()).arg(color.blue());
    ui->lineEdit_2->setText(string);
}

void Widget::on_pushButton_3_clicked()
{
    QColor color = QColorDialog::getColor(Qt::gray,this,"text color",QColorDialog::ShowAlphaChannel);
    QString string = QString("\"background-color: rgb(%1, %2, %3);\"").arg(color.red()).arg(color.green()).arg(color.blue());
    ui->lineEdit_3->setText(string);
}
