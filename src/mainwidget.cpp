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

    char opera = 0;
    double val1 = 0;
    double val2 = 0;
    int flags = 1;

    for (int i = 0; i < strlen(buf); i++)
        if (!isdigit(buf[i]))
        {
            opera = buf[i];
            flags += i;
            break;
        }
    double retVal;
    val1 = atof(buf);
    val2 = atof(buf + flags);

    if (val2 == 0)
    {
        ui->label->setText(buf);
        val.clear();
        memset(buf + flags, 0, strlen(buf) - flags);
        sprintf(buf, "%lf", retVal);
        removeZero(buf);
        val = buf;

        ui->lineEdit->setText(val);
        return;
    }

    if (opera == '+')
    {
        retVal = val1 + val2;
        memset(buf, 0, len);
        sprintf(buf, "%lf+%lf", val1, val2);
    }
    else if (opera == '-')
    {
        retVal = val1 - val2;
        memset(buf, 0, len);
        sprintf(buf, "%lf-%lf", val1, val2);
    }
    else if (opera == '*')
    {
        retVal = val1 * val2;
        memset(buf, 0, len);
        sprintf(buf, "%lf*%lf", val1, val2);
    }
    else if (opera == '/')
    {
        retVal = val1 / val2;
        memset(buf, 0, len);
        sprintf(buf, "%lf/%lf", val1, val2);
    }
    else if (opera == '^')
    {
        retVal = pow(val1, val2);
        memset(buf, 0, len);
        sprintf(buf, "%lf^%lf", val1, val2);
    }
    else if (opera == '%')
    {
        retVal = (int)val1 % (int)val2;
        memset(buf, 0, len);
        sprintf(buf, "%lf%%%lf", val1, val2);
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
    if (val.endsWith("+") || val.endsWith("-") || val.endsWith("/") ||
        val.endsWith("*") || val.endsWith("^") || val.endsWith("%"))
        val.chop(1);

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
    if (val.endsWith("+") || val.endsWith("-") || val.endsWith("/") ||
        val.endsWith("*") || val.endsWith("^") || val.endsWith("%"))
        val.chop(1);

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
    if (val.endsWith("+") || val.endsWith("-") || val.endsWith("/") ||
        val.endsWith("*") || val.endsWith("^") || val.endsWith("%"))
        val.chop(1);

    val += "^";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_mod_clicked()
{
    if (val.endsWith("+") || val.endsWith("-") || val.endsWith("/") ||
        val.endsWith("*") || val.endsWith("^") || val.endsWith("%"))
        val.chop(1);

    val += "%";
    ui->lineEdit->setText(val);
}

void MainWidget::on_btn_mul_clicked()
{
    if (val.endsWith("+") || val.endsWith("-") || val.endsWith("/") ||
        val.endsWith("*") || val.endsWith("^") || val.endsWith("%"))
        val.chop(1);

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
    if (val.endsWith("+") || val.endsWith("-") || val.endsWith("/") ||
        val.endsWith("*") || val.endsWith("^") || val.endsWith("%"))
        val.chop(1);

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