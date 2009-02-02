#include <QApplication>
#include <QGraphicsView>

#include "game.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	GoferSmash view;

	view.resize(450, 450);

	view.show();

	return app.exec();
}
