#include "mainwidget.h"
#include "./ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_num_0_clicked()
{
    val += "0";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_point_clicked()
{
    val += ".";
    ui->lineEdit->setText(val);
}

void removeZero(char *str)
{
    int len = strlen(str);
    int dotPos = -1;
    for (int i = 0; i < len; i++)
        if (str[i] == '.')
        {
            dotPos = i;
            break;
        }

    if (dotPos != -1)
        for (int i = len - 1; i >= dotPos; i--)
        {
            if (str[i] == '0')
                str[i] = '\0';
            else if (str[i] == '.')
            {
                str[i] = '\0';
                break;
            }
            else
                break;
        }
}

void MainWidget::on_btn_ret_clicked()
{
    qsizetype len = val.length();
    char *buf = new char[len]();
    strcpy(buf, val.toStdString().data());
    char *opera = nullptr;
    double retVal;

    // 识别操作
    if (opera = strstr(buf, "+"))
    {
        double valA = atof(buf);
        double valB = atof(opera + 1);
        retVal = valA + valB;
    }
    else if (opera = strstr(buf, "-"))
    {
        double valA = atof(buf);
        double valB = atof(opera + 1);
        retVal = valA - valB;
    }
    else if (opera = strstr(buf, "*"))
    {
        double valA = atof(buf);
        double valB = atof(opera + 1);
        retVal = valA * valB;
    }
    else if (opera = strstr(buf, "/"))
    {
        double valA = atof(buf);
        double valB = atof(opera + 1);
        retVal = valA / valB;
    }
    else if (opera = strstr(buf, "%"))
    {
        int valA = atoi(buf);
        int valB = atoi(opera + 1);
        retVal = (valA % valB);
    }
    else if (opera = strstr(buf, "^"))
    {
        double valA = atof(buf);
        double valB = atof(opera + 1);
        retVal = pow(valA, valB);
    }
    else
    {
        delete[] buf;
        return;
    }
    ui->label->setText(buf);
    memset(buf, 0, len);
    sprintf(buf, "%lf", retVal);
    removeZero(buf);
    val = buf;

    ui->lineEdit->setText(val);
    delete[] buf;
}

void MainWidget::on_num_1_clicked()
{
    val += "1";
    ui->lineEdit->setText(val);
}

void MainWidget::on_num_2_clicked()
{
    val += "2";
    ui->lineEdit->setText(val);
}

void MainWidget::on_num_3_clicked()
{
    val += "3";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_add_clicked()
{
    val += "+";
    ui->lineEdit->setText(val);
}

void MainWidget::on_num_4_clicked()
{
    val += "4";
    ui->lineEdit->setText(val);
}

void MainWidget::on_num_5_clicked()
{
    val += "5";
    ui->lineEdit->setText(val);
}

void MainWidget::on_num_6_clicked()
{
    val += "6";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_sub_clicked()
{
    val += "-";
    ui->lineEdit->setText(val);
}

void MainWidget::on_num_7_clicked()
{
    val += "7";
    ui->lineEdit->setText(val);
}

void MainWidget::on_num_8_clicked()
{
    val += "8";
    ui->lineEdit->setText(val);
}

void MainWidget::on_num_9_clicked()
{
    val += "9";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_pow_clicked()
{
    val += "^";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_mod_clicked()
{
    val += "%";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_mul_clicked()
{
    val += "*";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_del_clicked()
{
    val = val.remove(val.length() - 1, 1);
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_div_clicked()
{
    val += "/";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_clear_clicked()
{
    val.clear();
    ui->lineEdit->setPlaceholderText("请输入值");
    ui->lineEdit->setText(val);
    ui->label->setText("");
}