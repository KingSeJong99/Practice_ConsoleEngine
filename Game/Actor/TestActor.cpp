#include"TestActor.h"
#include"Core/Input.h"
#include"Engine/Engine.h"
#include<iostream>
#include<Windows.h>

using namespace Mint;

TestActor::TestActor()
	:super('T', Vector2(5, 5))
{
}
void TestActor::BeginPlay()
{
	// 오버라이드 하였으므로 상위 함수를 호출해주어야 한다
	// C++는 기본적으로 부모함수를 가리키는 포인터가 없다!!
	Actor::BeginPlay();

	// std::cout << "TestActor::BeginPlay().\n";
}

void TestActor::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);

	if (Mint::Input::Get().GetKeyDown('Q'))
	{
		// TODO: 게임 엔진 종료 요청
		Mint::Engine::Get().QuitEngine();
	}

	// 이동한다
	// if(Input::Get().GetKey('D'))
	if (Input::Get().GetKey(VK_RIGHT) && GetPosition().x < 20)
	{
		Vector2 newPosition = GetPosition();
		newPosition.x += 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_LEFT) && GetPosition().x > 0)
	{
		Vector2 newPosition = GetPosition();
		newPosition.x -= 1;
		SetPosition(newPosition);
	}

	// std::cout << "TestActor::Tick(). deltaTime" << deltaTime
	// 	<< ", FPS: " << (1.0f / deltaTime) << "\n";
}

void TestActor::Draw()
{
	Actor::Draw();
}
