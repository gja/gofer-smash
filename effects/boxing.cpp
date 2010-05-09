#include "boxing.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsItemAnimation>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTimeLine>

BoxingSmash::BoxingSmash(const QPoint &point, QGraphicsScene *parent) : Smash(point, parent) , powTimer(NULL), punchTimeline(NULL), pow(NULL), fist(NULL), punch(NULL)
{
	int x, y;
	QSize size = group->scene()->views()[0]->size();

	powTimer = new QTimer(this);
	punchTimeline = new QTimeLine(500, this);

	QPixmap t;
    t = QPixmap(":data/pow.png");
	t = t.scaled(size / 3);
	pow = new QGraphicsPixmapItem(t, group);
	pow->hide();
	pow->setZValue(1.0f);
	x = target.x() - t.width() / 2;
	y = target.y() - t.height() / 2;
	pow->setPos(x, y);

	t = QPixmap(":data/glove.png");
	t = t.scaledToHeight(size.height() / 6);
	y = target.y() - t.height() / 2;
	fist = new QGraphicsPixmapItem(t, group);
	fist->hide();
	fist->setZValue(0.5f);
	fist->setPos(size.width(), y);

	punch = new QGraphicsItemAnimation(this);
	punch->setItem(fist);
	punch->setTimeLine(punchTimeline);
	punch->setPosAt(1.0f, target);
}

void BoxingSmash::start()
{
	fist->show();
	punchTimeline->start();
	powTimer->singleShot(400, this, SLOT(timeout()));
}

void BoxingSmash::timeout()
{
	pow->show();
	powTimer->singleShot(600, this, SLOT(finished()));
}
