#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

class GopherSmash : public QGraphicsView {

	Q_OBJECT

    public:
	GopherSmash(QWidget *parent) : QGraphicsView(parent) {}
	GopherSmash() : QGraphicsView() {}
};

#endif
