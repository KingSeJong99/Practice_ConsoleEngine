#include "TestActor.h"
#include<iostream>

void TestActor::BeginPlay()
{
	// 오버라이드 하였으므로 상위 함수를 호출해주어야 한다
	// C++는 기본적으로 부모함수를 가리키는 포인터가 없다!!
	Actor::BeginPlay();

	std::cout << "TestActor::BeginPlay().\n";
}

void TestActor::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);

	std::cout << "TestActor::Tick(). deltaTime" << deltaTime
		<< ", FPS: " << (1.0f / deltaTime) << "\n";
}

void TestActor::Draw()
{
	Actor::Draw();
}
