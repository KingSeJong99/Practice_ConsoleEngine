#pragma once
#include"Actor/Actor.h"

class Player : public Mint::Actor
{
	RTTI_DECLARATIONS(Player, Actor)

public:
	Player();

	// public을 protected로 바꿔야했으나 놓쳐서 이제 바꿈
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;
};

