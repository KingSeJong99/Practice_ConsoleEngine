#include "Game.h"
#include"Level/SokobanLevel.h"
#include"Level/MenuLevel.h"

#include<iostream>

// 정적 변수 초기화하기
Game* Game::instance = nullptr;

Game::Game()
{
	instance = this;

	// 두 레벨 생성 및 배열에 추가하기
	levels.emplace_back(new SokobanLevel());
	levels.emplace_back(new MenuLevel());

	// 시작 상태(레벨) 설정하기
	state = State::GamePlay;

	// 게임 시작 시 활성화할 레벨 설정하기
	mainLevel = levels[0];
}

Game::~Game()
{
	// 중복 제거 방지
	mainLevel = nullptr;

	// 모든 레벨 삭제하기
	for (Level*& level : levels)
	{
		delete level;
		level = nullptr;
	}

	// 배열 정리하기
	levels.clear();
}

void Game::ToggleMenu()
{
	// 화면 지우기
	// system은 콘솔 명령어 실행 함수이다. "cls" 명령어 실행하기
	// cls -> clear screen
	system("cls");

	// 변경할 인덱스 계산하기
	// 현재 활성된 레벨 인덱스가 1이면 0으로 설정하기
	// 현재 활성된 레벨 인덱스가 0이면 1로 설정하기
	// -> 1 - x 기법!
	
	int stateIndex = (int)state;			// static_cast
	int nextState = 1 - stateIndex;			// 1 - x 기법
	state = (State)nextState;				// static_cast

	// 메인 레벨 설정하기
	mainLevel = levels[static_cast<int>(state)];
}

Game& Game::Get()
{
	if (!instance)
	{
		std::cerr << "Game::Get() - instance is null\n";
		__debugbreak();
	}

	// 정적 변수 반환하기
	return *instance;
}