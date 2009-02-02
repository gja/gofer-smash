#ifndef BOXING_H
#define BOXING_H

#include "smash.h"

class QTimer;
class QTimerLine;
class QGraphicsPixmapItem;
class QGraphicsScene;

class BoxingSmash : public Smash {
	Q_OBJECT

	QTimer *powTimer;
	QTimerLine *punchTimeline;

	QGraphicsPixmapItem *pow;

    public:
	
	// Start the Smash
	void start();

	BoxingSmash(const QPoint &point, QGraphicsScene *parent = NULL);

    public slots:

	// This is called when a timer times out
	void timeout();
};

#endif
