#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include "VideoJuego.h"
#include <chrono>

namespace Ui {
class Juego;
}

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit Juego(QWidget *parent = nullptr);
    void setVideoJuego(VideoJuego* videoJuego);
    ~Juego();

protected:
    void showEvent(QShowEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private slots:
    void signalJuegoBatallaNaval(std::chrono::steady_clock::time_point tiempoIncial = std::chrono::steady_clock::now());

    void on_pushButton_clicked();

private:
    Ui::Juego *ui;
    VideoJuego* videoJuego;
};

#endif // JUEGO_H
