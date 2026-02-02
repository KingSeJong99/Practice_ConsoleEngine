#include "Target.h"

Target::Target(const Vector2& position) : super('T', position, Color::Green)
{
	// 그리기 우선순위를 설정한다
	sortingOrder = 0;
}