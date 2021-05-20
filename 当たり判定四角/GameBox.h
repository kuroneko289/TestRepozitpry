#pragma once

//2Dベクトル
struct Vector2
{
	float x, y;
};

using Position2 = Vector2;

struct Rect
{
	Position2 center;//中心的
	float w;
	float h;
	float Left()const;
	float Top()const;
	float Right()const;
	float Bottom()const;
	float Width()const;
	float Height()const;

};

