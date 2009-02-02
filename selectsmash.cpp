#include "game.h"
#include "smash.h"

#include "boxing.h"
#include "pie.h"

#include <QPoint>

Smash *GoferSmash::selectSmash(const QPoint &point)
{
	switch (rand() % 2) {
		case 0: return new BoxingSmash(point, scene);
		case 1: return new PieSmash(point, scene);
	}
}
