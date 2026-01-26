#include"Actor.h"

namespace Mint
{
	Actor::Actor()
	{

	}
	Actor::~Actor()
	{

	}

	void Actor::BeginPlay()
	{
		// 이벤트를 받은 후에는 플래그를 설정한다
		hasBeganPlay = true;
	}
	void Actor::Tick(float deltaTime)
	{

	}
	void Actor::Draw()
	{

	}
}