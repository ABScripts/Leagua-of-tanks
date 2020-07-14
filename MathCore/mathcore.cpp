#include "MathCore/mathcore.h"

QPoint MathCore::pointOnCircle(const StandartTank * const tank, qreal circleRadius, qreal angle)
{
    qreal radAngle = qDegreesToRadians(angle);

    // parametric equation
    return QPoint( circleRadius * qCos(radAngle) + tank->x() + tank->rect().width() / 2  ,
                   circleRadius * qSin(radAngle) + tank->y() + tank->rect().height() / 2 );
}
