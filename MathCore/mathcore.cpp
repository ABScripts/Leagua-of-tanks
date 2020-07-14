#include "mathcore.h"

inline QPoint MathCore::pointOnCircle(const StandartTank * const tank, double circleRadius, double angle)
{
    double radAngle = qDegreesToRadians(angle);

    // parametric equation
    return QPoint( circleRadius * qCos(radAngle) + tank->x() + tank->rect().width() / 2  ,
                   circleRadius * qSin(radAngle) + tank->y() + tank->rect().height() / 2 );
}
