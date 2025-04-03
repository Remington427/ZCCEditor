#include "ScalableItem.h"
#include <QGraphicsScene>
#include <QGraphicsSceneWheelEvent>
#include <iostream>
#include <algorithm>

ScalableItem::ScalableItem()
{
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
	zoom = 1.0;
	min_width = 100;
	min_height = 100;
	max_width = 1000;
	max_height = 1000;
}

void ScalableItem::wheelEvent(QGraphicsSceneWheelEvent* event)
{


	float steps = float(event->delta()) / (15.f * 8.f * 10.f);

	std::cout << "Wheel event delta = " << steps << std::endl;
	QSizeF size = boundingRect().size() * (scale() + steps);
	if (steps != 0.f)
	{
		if (size.width() > min_width && size.height() > min_height  && size.width() < max_width && size.height() < max_height)
		{
			zoom += steps;
			setScale(zoom);
		}
	}
	QGraphicsPixmapItem::wheelEvent(event);
}

QVariant ScalableItem::itemChange(GraphicsItemChange change, const QVariant& value)
{
	QSizeF size = boundingRect().size() * scale();
	int _w = size.width();
	int _h = size.height();
	if (change == ItemPositionChange && scene()) {
		// value is the new position.
		QPointF newPos = value.toPointF();
		QRectF rect(0,0,1049,908);

		if (!rect.contains(newPos.x() - _w, newPos.y() - _h) || !rect.contains(newPos.x() - _w, newPos.y()) || !rect.contains(newPos.x(), newPos.y()) || !rect.contains(newPos.x(), newPos.y() - _h)) {
			// Keep the item inside the scene rect.
			newPos.setX(qMin(rect.right() - _w, qMax(newPos.x(), rect.left())));
			newPos.setY(qMin(rect.bottom() - _h, qMax(newPos.y(), rect.top())));
			return newPos;
		}
	}
	return QGraphicsPixmapItem::itemChange(change, value);
}
