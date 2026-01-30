#include"Player.h"
#include"Core/Input.h"
#include"Engine/Engine.h"
#include"Actor/Box.h"
#include"Level/Level.h"
#include<iostream>
#include<Windows.h>

using namespace Mint;

Player::Player()
	:super('P', Vector2(5, 5), Color::Red)
{
	// 그리기 우선 순위(값이 크면 우선순위가 높다)
	sortingOrder = 10;
}

void Player::BeginPlay()
{
	// 오버라이드 하였으므로 상위 함수를 호출해주어야 한다
	// C++는 기본적으로 부모함수를 가리키는 포인터가 없다!!
	Actor::BeginPlay();

	// std::cout << "TestActor::BeginPlay().\n";
}

void Player::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);

	if (Mint::Input::Get().GetKeyDown('Q'))
	{
		// TODO: 게임 엔진 종료 요청
		Mint::Engine::Get().QuitEngine();
	}

	// 스페이스로 박스를 생성한다
	// vk->virtual key
	if (Input::Get().GetKeyDown(VK_SPACE))
	{
		// 박스를 생성한다
		// 템플릿으로 구조를 변경할 수 있다
		if (owner)
		{
			owner->AddNewActor(new Box(GetPosition()));
		}
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

	if (Input::Get().GetKey(VK_DOWN) && GetPosition().y < 15)
	{
		Vector2 newPosition = GetPosition();
		newPosition.y += 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_UP) && GetPosition().y > 0)
	{
		Vector2 newPosition = GetPosition();
		newPosition.y -= 1;
		SetPosition(newPosition);
	}

	// std::cout << "TestActor::Tick(). deltaTime" << deltaTime
	// 	<< ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Player::Draw()
{
	Actor::Draw();
 }
