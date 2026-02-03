#include "Wall.h"

Wall::Wall(const Vector2& position)
	: super("#", position, Color::White)
{
	// 그리기 우선순위를 설정한다
	sortingOrder = 0;
}
