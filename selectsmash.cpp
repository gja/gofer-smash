#include "game.h"
#include "smash.h"

#include "effects/boxing.h"

#include <QPoint>

Smash *GoferSmash::selectSmash(const QPoint &point)
{
	return new BoxingSmash(point, this);	
}
