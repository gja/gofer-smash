#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class QGraphicsScene;
class QGraphicsItemGroup;
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
};

#endif
