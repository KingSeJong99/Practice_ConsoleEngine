#include"MenuLevel.h"
#include"Game/Game.h"
#include"Core/Input.h"
#include"Util/Util.h"
#include<iostream>

MenuLevel::MenuLevel()
{
	// 메뉴 아이템 생성하기
	items.emplace_back(new MenuItem(
		"Resume Game",
		[]() 
		{
			// 메뉴 토글 함수 호출하기
			Game::Get().ToggleMenu();
		}
	));

	// 메뉴 아이템 생성하기
	items.emplace_back(new MenuItem(
		"Quit Game",
		[]()
		{
			// 게임 종료
			Game::Get().QuitEngine();
		}
	));
}

MenuLevel::~MenuLevel()
{
	// 메뉴 아이템 제거하기
	for (MenuItem*& item : items)
	{
		delete item;
		item = nullptr;
	}

	items.clear();
}

void MenuLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 입력의 처리(방향키 위, 아래, 엔터, ESC
	// 배열의 길이
	static int length = static_cast<int>(items.size());

	if (Input::Get().GetKeyDown(VK_UP))
	{
		// 인덱스 돌리기
		// 환형 큐 
		currentIndex = (currentIndex - 1 + length) % length;
	}

	if (Input::Get().GetKeyDown(VK_DOWN))
	{
		// 인덱스 돌리기, 나머지 연산을 활용하여 인덱스를 벗어나지 않도록 한다
		currentIndex = (currentIndex + 1) % length;
	}

	if (Input::Get().GetKeyDown(VK_RETURN))
	{
		items[currentIndex]->onSelected()
	}

	if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		// 메뉴 토글
		Game::Get().ToggleMenu();

		// 인덱스 초기화
		currentIndex = 0;
	}
}

void MenuLevel::Draw()
{
	// 메뉴 제목 출력하기
	Util::SetConsolePosition(Vector2::Zero);
	Util::SetConsoleTextColor(Color::White);

	// 텍스트 출력
	std::cout << "Sokoban Game\n\n";

	// 메뉴 아이템 출력하기
	for (int ix = 0; ix < static_cast<int>(items.size()); ++ix)
	{
		Color textColor =
			(ix == currentIndex) ? selectedColor : unselectedColor;

		// 색상 설정하기
		Util::SetConsoleTextColor(textColor);

		// 텍스트 출력하기
		std::cout << items[ix]->text << "\n";
	}
}