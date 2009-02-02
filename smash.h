#ifndef SMASH_H
#define SMASH_H

#include <QObject>
#include <QPoint>

// This class is used to punch someone
class Smash : public QObject {
	Q_OBJECT

	QPoint target;

    public slots:
	// Call me when you are finished with the class
	void finished();

    public:
	Smash(const QPoint &target, QObject *parent = NULL);
	virtual ~Smash();

	virtual void start() = 0;

    signals:
	// emitted when this is done
	void deleteMe(Smash *);
};
#endif
