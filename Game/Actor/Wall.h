#pragma once
#include "Actor\Actor.h"

using namespace Mint;

class Wall : public Actor
{
	RTTI_DECLARATIONS(Wall, Actor)

public:
	// 위치 지정이 가능하도록 생성자를 선언한다
	Wall(const Vector2& position);
};