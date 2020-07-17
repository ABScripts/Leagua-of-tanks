#ifndef MATH_CORE
#define MATH_CORE

#include "Tanks/tank.h"

class MathCore {
public:
    static QPoint pointOnCircle(const Tank * tank, qreal circleRadius, qreal angle);
};

#endif
