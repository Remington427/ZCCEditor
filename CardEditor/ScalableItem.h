#ifndef SCALABLEITEM_H
#define SCALABLEITEM_H


#include <QGraphicsPixmapItem>

#pragma once
class ScalableItem : public QGraphicsPixmapItem
{
	public:
		ScalableItem();
	protected:
		void wheelEvent(QGraphicsSceneWheelEvent* event);
		QVariant itemChange(GraphicsItemChange change, const QVariant& value);
	private:
		float zoom;
		int min_width;
		int min_height;
		int max_width;
		int max_height;
};


#endif // !SCALABLEITEM_H
