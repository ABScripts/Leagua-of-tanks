#ifndef MATH_CORE
#define MATH_CORE

#include <QPoint>
class TankView;

class MathCore {
public:
    static QPoint pointOnCircle(const TankView * tank, qreal circleRadius, qreal angle);
};

#endif
