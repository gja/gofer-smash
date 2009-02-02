#include "smash.h"

Smash::Smash(const QPoint &point, QObject *parent) : QObject(parent), target(point)
{}

Smash::~Smash()
{}

void Smash::finished()
{
	emit deleteMe(this);
}
