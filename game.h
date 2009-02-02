#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class GoferSmash : public QGraphicsView {

	Q_OBJECT

	QGraphicsScene *scene;

    public:
	GoferSmash(QWidget *parent = NULL);
	~GoferSmash();

	void mousePressEvent(QMouseEvent *event);
};

#endif
