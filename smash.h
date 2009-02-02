#ifndef SMASH_H
#define SMASH_H

#include <QObject>
#include <QPoint>

// This class is used to punch someone
class Smash : public QObject {
	Q_OBJECT

	QPoint target;

	// Call me when you are finished with the class
	inline void finished()
	{
		emit deleteMe(this);
	}

    public:
	Smash(const QPoint &target, QObject *parent = NULL);
	virtual ~Smash();

    signals:
	// emitted when this is done
	void deleteMe(Smash *);
};
#endif
