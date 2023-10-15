#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_num_0_clicked();

    void on_btn_point_clicked();

    void on_btn_ret_clicked();

    void on_num_1_clicked();

    void on_num_2_clicked();

    void on_num_3_clicked();

    void on_btn_add_clicked();

    void on_num_4_clicked();

    void on_num_5_clicked();

    void on_num_6_clicked();

    void on_btn_sub_clicked();

    void on_num_7_clicked();

    void on_num_8_clicked();

    void on_num_9_clicked();

    void on_btn_pow_clicked();

    void on_btn_mod_clicked();

    void on_btn_mul_clicked();

    void on_btn_del_clicked();

    void on_btn_div_clicked();

    void on_btn_clear_clicked();

private:
    Ui::MainWidget *ui;

    QString val;
 };
#endif // MAINWIDGET_H
