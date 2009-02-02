#include "game.h"
#include "smash.h"

#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsLineItem>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QList>

GoferSmash::GoferSmash(QWidget *parent): QGraphicsView(parent), scene(NULL), board(NULL), deleteQueue(NULL), smash(NULL), state(SmashHidden)
{
	// Create A Blank Scene
	scene = new QGraphicsScene();
	scene->setBackgroundBrush(Qt::white);
	setScene(scene);

	setRenderHints(QPainter::Antialiasing);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	initializeGameBoard();

	connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));
	timer.start(500);
}

void GoferSmash::mousePressEvent(QMouseEvent *event)
{
	if (! smash->isUnderMouse() || state != SmashVisible)
		return;

	state = SmashInProgress;

	Smash *s = selectSmash(smash->pos().toPoint() + QPoint( width() / 6, height() / 6));
	connect(s, SIGNAL(deleteMe(Smash *)), this, SLOT(deleteOldSmash(Smash *)));
	s->start();
}

GoferSmash::~GoferSmash()
{
	delete scene;
}

void GoferSmash::initializeGameBoard()
{
	int x = size().width() / 3;
	int y = size().height() / 3;
	int w[3], h[3];
	w[0] = 0;
	w[1] = x + 1;
	w[2] = 2*x + 2;
	h[0] = 0;
	h[1] = y + 1;
	h[2] = 2*y + 2;

	points.clear();
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			points<<QPoint(w[x], h[y]);

	qDebug()<<"Initializing Board";

	x = size().width();
	y = size().height();

	int x_3 = x / 3;
	int y_3 = y / 3;

	if (board)
		delete board;

	board = new QGraphicsItemGroup;
	board->setZValue(-1.0f);
	new QGraphicsLineItem( x_3 + 1, 0, x_3 + 1, y, board);
	new QGraphicsLineItem( 2 * x_3 + 2, 0, 2 * x_3 + 2, y, board);
	new QGraphicsLineItem( 0, y_3 + 1, x, y_3 + 1, board);
	new QGraphicsLineItem( 0, 2 * y_3 + 2, x, 2 * y_3 + 2, board);
	scene->addItem(board);

	if (smash)
		delete smash;

	QPixmap t = QPixmap("data/smash.jpg").scaled(size() / 3);
	smash = new QGraphicsPixmapItem(t);
	smash->hide();
	smash->setZValue(-1.0f);
	scene->addItem(smash);

	scene->update();
}

void GoferSmash::resizeEvent(QResizeEvent *event)
{
	if (event->size() != event->oldSize())
		initializeGameBoard();
}

void GoferSmash::deleteOldSmash(Smash *s)
{
	if (deleteQueue != NULL)
		delete deleteQueue;

	deleteQueue = s;

	smash->hide();
	state = SmashHidden;
}

void GoferSmash::timeout()
{
	int x, y;
	QPoint point;

	switch (state) {
		case SmashVisible:
			smash->hide();
			state = SmashHidden;
			break;
		case SmashHidden:
			point = points[rand() % 9];
			smash->setPos(point);
			smash->show();
			state = SmashVisible;
			break;
		case SmashInProgress:
			break;
	}

}
