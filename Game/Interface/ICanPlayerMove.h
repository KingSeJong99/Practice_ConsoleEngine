#pragma once

#include"Math/Vector2.h"

// 플레이어가 이동할 위치를 판단해줌
// C++에서 인터페이스는 순수 가상함수를 가지는 클래스이다
class ICanPlayerMove
{
public:
	// 플레이어가 이동가능한지 문의할 때 사용할 함수이다
	// playerPosition: 플레이어의 현재 위치임
	// nextPosition: 플레이어가 이동하려는 위치임
	
	virtual bool CanMove(
		const Mint::Vector2& playerPosition,
		const Mint::Vector2& nextPosition
	) = 0;
};