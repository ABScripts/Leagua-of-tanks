#ifndef MATH_CORE
#define MATH_CORE

#include <QPoint>

QT_BEGIN_NAMESPACE
class TankView;
QT_END_NAMESPACE

class MathCore {
public:
    static QPoint pointOnCircle(const TankView * tank, qreal circleRadius, qreal angle);
};

#endif
