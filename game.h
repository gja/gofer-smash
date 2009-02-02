#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QPoint>
#include <QList>
#include <QTimer>

class QGraphicsScene;
class QGraphicsItemGroup;
class QGraphicsPixmapItem;
class Smash;

class GoferSmash : public QGraphicsView {

	Q_OBJECT

	// The Graphics Scene
	QGraphicsScene *scene;

	// A Group of Items with the board
	QGraphicsItemGroup *board;

	// Deletion Queue (max 1 item)
	Smash *deleteQueue;

	// Initialize the gameboard
	void initializeGameBoard();

	// Selects a Smash, and Creates it
	Smash *selectSmash(const QPoint &point);

	// The Photo to Smash
	QGraphicsPixmapItem *smash;

	enum State {
		SmashHidden = 0,
		SmashVisible,
		SmashInProgress
	};
	State state;

	// List of all the Points
	QList <QPoint> points;

	QTimer timer;

    public:
	// Constructor/Destructor
	GoferSmash(QWidget *parent = NULL);
	~GoferSmash();

	// Called on Mouse Click and Resize
	void mousePressEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent *event);

    public slots:

	// Deletes an old smash item
	void deleteOldSmash(Smash *);

	// Timeout, either show or hide
	void timeout();
};

#endif
