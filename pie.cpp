#include "pie.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsItemAnimation>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTimeLine>

#include "pie_png.h"
#include "splat_png.h"

PieSmash::PieSmash(const QPoint &point, QGraphicsScene *parent) : Smash(point, parent) , splatTimer(NULL), throwTimeline(NULL), splat(NULL),pie(NULL), throwing(NULL)
{
	int x, y;
	QSize size = group->scene()->views()[0]->size();

	splatTimer = new QTimer(this);
	throwTimeline = new QTimeLine(500, this);

	QPixmap t;
	t.loadFromData(splat_png, sizeof(splat_png));
	t = t.scaled(size / 3);
	splat = new QGraphicsPixmapItem(t, group);
	splat->hide();
	splat->setZValue(1.0f);
	x = target.x() - t.width() / 2;
	y = target.y() - t.height() / 2;
	splat->setPos(x, y);

	t.loadFromData(pie_png, sizeof(pie_png));
	t = t.scaledToHeight(size.height() / 3);
	y = target.y() - t.height() / 2;
	pie = new QGraphicsPixmapItem(t, group);
	pie->hide();
	pie->setZValue(0.5f);
	pie->setPos(-t.width(), y);

	throwing = new QGraphicsItemAnimation(this);
	throwing->setItem(pie);
	throwing->setTimeLine(throwTimeline);
	throwing->setPosAt(1.0f, QPoint(target.x(), y));
}

void PieSmash::start()
{
	pie->show();
	throwTimeline->start();
	splatTimer->singleShot(400, this, SLOT(timeout()));
}

void PieSmash::timeout()
{
	pie->hide();
	splat->show();
	splatTimer->singleShot(600, this, SLOT(finished()));
}
