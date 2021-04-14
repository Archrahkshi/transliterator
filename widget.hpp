#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_HPP

