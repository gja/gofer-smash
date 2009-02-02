#include <QApplication>
#include <QGraphicsView>

#include "game.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	GoferSmash view;

	view.resize(302, 302);

	view.show();

	return app.exec();
}
