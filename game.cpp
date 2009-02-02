#include "game.h"

#include <QDebug>
#include <QMouseEvent>

GoferSmash::GoferSmash(QWidget *parent): QGraphicsView(parent)
{
	// Create A Blank Scene
	scene = new QGraphicsScene();
	scene->setBackgroundBrush(Qt::black);
	setScene(scene);

	setRenderHints(QPainter::Antialiasing);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void GoferSmash::mousePressEvent(QMouseEvent *event)
{
	
}

GoferSmash::~GoferSmash()
{
	delete scene;
}
