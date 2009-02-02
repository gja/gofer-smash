#include "smash.h"

#include <QGraphicsScene>

Smash::Smash(const QPoint &point, QGraphicsScene *parent) : QObject(), target(point), group(NULL)
{
	group = new QGraphicsItemGroup;
	parent->addItem(group);
}

Smash::~Smash()
{
	group->hide();
	group->scene()->removeItem(group);
	delete group;
}

void Smash::finished()
{
	emit deleteMe(this);
}
