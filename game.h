#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class GoferSmash : public QGraphicsView {

	Q_OBJECT

    public:
	GoferSmash(QWidget *parent) : QGraphicsView(parent) { GoferSmash(); }
	GoferSmash() : QGraphicsView() {}
};

#endif
