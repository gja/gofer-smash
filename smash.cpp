#include "smash.h"

#include <QGraphicsScene>

Smash::Smash(const QPoint &point, QGraphicsScene *parent) : QObject(), target(point), group(NULL)
{
	group = new QGraphicsItemGroup;
	parent->addItem(group);
}

Smash::~Smash()
{
	delete group;
}

void Smash::finished()
{
	group->hide();
	group->scene()->removeItem(group);
	emit deleteMe(this);
}
