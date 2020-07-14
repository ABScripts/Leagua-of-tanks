#ifndef MATH_CORE
#define MATH_CORE

#include <qmath.h>
#include "standarttank.h"


class MathCore {
public:
    static inline QPoint pointOnCircle(const StandartTank * const tank, double circleRadius, double angle);
};

#endif
