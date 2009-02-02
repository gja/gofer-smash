#include "game.h"
#include "smash.h"

#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsLineItem>

GoferSmash::GoferSmash(QWidget *parent): QGraphicsView(parent), scene(NULL), board(NULL), deleteQueue(NULL)
{
	// Create A Blank Scene
	scene = new QGraphicsScene();
	scene->setBackgroundBrush(Qt::white);
	setScene(scene);

	setRenderHints(QPainter::Antialiasing);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	initializeGameBoard();
}

void GoferSmash::mousePressEvent(QMouseEvent *event)
{
	Smash *smash = selectSmash(event->pos());	
	connect(smash, SIGNAL(deleteMe(Smash *)), this, SLOT(deleteOldSmash(Smash *)));
	smash->start();
}

GoferSmash::~GoferSmash()
{
	delete scene;
}

void GoferSmash::initializeGameBoard()
{
	qDebug()<<"Initializing Board";

	int x = size().width();
	int y = size().height();

	int x_3 = x / 3;
	int y_3 = y / 3;

	if (board)
		delete board;

	board = new QGraphicsItemGroup;
	new QGraphicsLineItem( x_3 + 1, 0, x_3 + 1, y, board);
	new QGraphicsLineItem( 2 * x_3 + 2, 0, 2 * x_3 + 2, y, board);
	new QGraphicsLineItem( 0, y_3 + 1, x, y_3 + 1, board);
	new QGraphicsLineItem( 0, 2 * y_3 + 2, x, 2 * y_3 + 2, board);
	scene->addItem(board);

	scene->update();
}

void GoferSmash::resizeEvent(QResizeEvent *event)
{
	if (event->size() != event->oldSize())
		initializeGameBoard();
}

void GoferSmash::deleteOldSmash(Smash *smash)
{
	if (deleteQueue != NULL)
		delete deleteQueue;

	deleteQueue = smash;
}
