#ifndef BOXING_H
#define BOXING_H

#include "smash.h"

class QTimer;
class QTimerLine;

class BoxingSmash : public Smash {
	QTimer *powTimer;
	QTimerLine *punchTimeline;
    public:
	
	// Start the Smash
	void start();

	inline BoxingSmash(const QPoint &point, QObject *parent = NULL) : Smash(point, parent) {}
};

#endif
