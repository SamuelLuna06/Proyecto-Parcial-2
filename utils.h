#ifndef UTILS_H
#define UTILS_H

#include "QHBoxLayout"

class Utils
{
public:
    Utils();

    static void limpiarLayout(QHBoxLayout* layout);
    static void limpiarLayout(QVBoxLayout* layout);
};

#endif // UTILS_H
