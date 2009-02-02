#ifndef BOXING_H
#define BOXING_H

#include "smash.h"

class QTimer;
class QTimeLine;
class QGraphicsPixmapItem;
class QGraphicsItemAnimation;
class QGraphicsScene;

class BoxingSmash : public Smash {
	Q_OBJECT

	QTimer *powTimer;
	QTimeLine *punchTimeline;

	QGraphicsPixmapItem *pow;
	QGraphicsPixmapItem *fist;
	QGraphicsItemAnimation *punch;

    public:
	
	// Start the Smash
	void start();

	BoxingSmash(const QPoint &point, QGraphicsScene *parent = NULL);

    public slots:

	// This is called when a timer times out
	void timeout();
};

#endif
