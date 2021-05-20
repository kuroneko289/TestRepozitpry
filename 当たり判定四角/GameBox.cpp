#include "GameBox.h"

float 
Rect:: Left()const
{
	return center.x - w;
}

float
Rect::Top()const
{
	return center.y - h;
}

float
Rect::Right()const
{
	return center.x + w;
}

float
Rect::Bottom()const
{
	return center.y + h;
}

float
Rect::Width()const
{
	return 2 * w;
}

float
Rect::Height()const
{
	return 2 * h;
}