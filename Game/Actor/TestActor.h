#pragma once
#include"Actor/Actor.h"

class TestActor : public Mint::Actor
{
	RTTI_DECLARATIONS(TestActor, Actor)

public:
	TestActor();

	// public을 protected로 바꿔야했으나 놓쳐서 이제 바꿈
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;
};

