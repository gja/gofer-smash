#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

class GoferSmash : public QGraphicsView {

	Q_OBJECT

	QGraphicsScene *scene;
	QGraphicsItemGroup *board;

	void initializeGameBoard();

    public:
	GoferSmash(QWidget *parent = NULL);
	~GoferSmash();

	void mousePressEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent *event);
};

#endif
