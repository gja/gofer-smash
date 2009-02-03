#ifndef PIE_H
#define PIE_H

#include "smash.h"

class QTimer;
class QTimeLine;
class QGraphicsPixmapItem;
class QGraphicsItemAnimation;
class QGraphicsScene;

class PieSmash : public Smash {
	Q_OBJECT

	QTimer *splatTimer;
	QTimeLine *throwTimeline;

	QGraphicsPixmapItem *splat;
	QGraphicsPixmapItem *pie;
	QGraphicsItemAnimation *throwing;

    public:
	
	// Start the Smash
	void start();

	PieSmash(const QPoint &point, QGraphicsScene *parent = NULL);

    public slots:

	// This is called when a timer times out
	void timeout();
};

#endif
