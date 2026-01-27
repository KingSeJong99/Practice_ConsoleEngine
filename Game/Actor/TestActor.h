#pragma once
#include"Actor/Actor.h"

class TestActor : public Mint::Actor
{
public:
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Draw() override;
};

