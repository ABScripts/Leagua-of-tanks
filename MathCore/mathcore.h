#ifndef MATH_CORE
#define MATH_CORE

#include <qmath.h>
#include "standarttank.h"


class MathCore {
public:
    static QPoint pointOnCircle(const StandartTank * const tank, qreal circleRadius, qreal angle);
};

#endif
