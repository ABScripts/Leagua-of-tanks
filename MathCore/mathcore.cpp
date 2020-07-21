#include "MathCore/mathcore.h"

#include "Views/tankview.h"
#include <qmath.h>

QPoint MathCore::pointOnCircle(const TankView * tank, qreal circleRadius, qreal angle)
{
    qreal radAngle = qDegreesToRadians(angle);

    return QPoint( circleRadius * qCos(radAngle) + tank->x() + tank->pixmap().width() * tank->scale() + tank->pixmap().width() * tank->scale() / 2 ,
                   circleRadius * qSin(radAngle) + tank->y() +  tank->pixmap().height() * tank->scale() + tank->pixmap().height() * tank->scale() / 2);
}
