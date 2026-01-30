#pragma once

#include"Actor/Actor.h"

using namespace Mint;

class Box : public Actor
{
	// RTTI를 등록한다
	RTTI_DECLARATIONS(Box, Actor)

public:
	Box(const Vector2& newPosition);
};

