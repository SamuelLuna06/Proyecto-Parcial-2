#include <QWidget>
#include "utils.h"

Utils::Utils() {}

void Utils::limpiarLayout(QHBoxLayout* boxLayout){
    QLayoutItem *item;
    while ((item = boxLayout->takeAt(0))) {
        if (QWidget *widget = item->widget()) {
            delete widget;
        }
        delete item;
    }
}

void Utils::limpiarLayout(QVBoxLayout* boxLayout){
    QLayoutItem *item;
    while ((item = boxLayout->takeAt(0))) {
        if (QWidget *widget = item->widget()) {
            delete widget;
        }
        delete item;
    }
}
