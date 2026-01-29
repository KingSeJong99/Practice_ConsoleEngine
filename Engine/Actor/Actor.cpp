#include"Actor.h"
#include<iostream>
#include<Windows.h>

namespace Mint
{
	Actor::Actor(
		const char image,
		const Vector2& position)
		: image(image), position(position)
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
		// 액터의 현재 좌표로 콘솔에서의 좌표를 이동한다
		COORD coord = {};
		coord.X = static_cast<short>(position.x);
		coord.Y = static_cast<short>(position.y);
		
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);

		// 이동한 좌표에서 글자 그리기
		std::cout << image;
	}

	// 프레임마다 호출하기에는 무리가 있다
	void Actor::SetPosition(const Vector2& newPosition)
	{
		// 액터의 좌표로 콘솔에서의 좌표 위치를 이동한다
		// 액터의 현재 좌표로 콘솔에서의 좌표를 이동한다
		COORD coord = {};
		coord.X = static_cast<short>(position.x);
		coord.Y = static_cast<short>(position.y);

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);
		// 해당 위치의 글자 값을 지우기(빈칸 그리기)
		std::cout << ' ';

		// 새로운 위치 설정
		position = newPosition;
	}
}