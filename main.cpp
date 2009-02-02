#include <QApplication>
#include <QGraphicsView>

#include "game.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	GoferSmash view;

	view.setGeometry(0, 0, 450, 450);

	view.show();

	return app.exec();
}
