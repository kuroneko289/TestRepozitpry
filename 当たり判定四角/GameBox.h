#pragma once

//2D�x�N�g��
struct Vector2
{
	float x, y;
};

using Position2 = Vector2;

struct Rect
{
	Position2 center;//���S�I
	float w;
	float h;
	float Left()const;
	float Top()const;
	float Right()const;
	float Bottom()const;
	float Width()const;
	float Height()const;

};

