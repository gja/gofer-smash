#ifndef SMASH_H
#define SMASH_H

#include <QObject>
#include <QPoint>
#include <QGraphicsItemGroup>

class QGraphicsScene;
class QGraphicsItemGroup;

// This class is used to punch someone
class Smash : public QObject {
	Q_OBJECT

    protected:
	QPoint target;
	QGraphicsItemGroup *group;

    public slots:
	// Call me when you are finished with the class
	void finished();

    public:
	Smash(const QPoint &target, QGraphicsScene *parent = NULL);
	virtual ~Smash();

	virtual void start() = 0;

    signals:
	// emitted when this is done
	void deleteMe(Smash *);
};
#endif
