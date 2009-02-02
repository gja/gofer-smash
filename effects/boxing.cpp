#include "boxing.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

BoxingSmash::BoxingSmash(const QPoint &point, QGraphicsScene *parent) : Smash(point, parent) , powTimer(NULL), punchTimeline(NULL), pow(NULL)
{
	powTimer = new QTimer;
}

void BoxingSmash::start()
{
	QPixmap t = QPixmap("data/pow.png").scaled(group->scene()->views()[0]->size() / 3);
	pow = new QGraphicsPixmapItem(t, group);

	int x = target.x() - t.size().width() / 2;
	int y = target.y() - t.size().height() / 2;

	pow->setPos(x, y);

	powTimer->singleShot(400, this, SLOT(timeout()));
}

void BoxingSmash::timeout()
{
	pow->hide();
	finished();
}
