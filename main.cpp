#include <QApplication>
#include <QGraphicsView>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QGraphicsView view;

	view.show();

	return app.exec();
}
