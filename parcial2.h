#ifndef PARCIAL2_H
#define PARCIAL2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Parcial2;
}
QT_END_NAMESPACE

class Parcial2 : public QMainWindow
{
    Q_OBJECT

public:
    Parcial2(QWidget *parent = nullptr);
    ~Parcial2();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_btnLogin_clicked();

private:
    Ui::Parcial2 *ui;
};
#endif // PARCIAL2_H
