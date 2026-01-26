#include"Level.h"
#include"Actor/Actor.h"

namespace Mint
{
	Level::Level()
	{
	}

	Level::~Level()
	{
		// 메모리 정리하기
		for (Actor*& actor : actors)
		{
			// Actor 객체의 메모리를 해제한다
			if (actor)
			{
				delete actor;
				actor = nullptr;
			}
		}

		// 배열 초기화하기
		actors.clear();
	}

	void Level::BeginPlay()
	{
		// Actor에 Event를 흘리기
		for (Actor* actor : actors)
		{
			// 이미 Beginplay가 호출된 Actor의 경우에는 건너뛰어야함
			if (actor->HasBeganPlay())
			{
				continue;
			}
			actor->BeginPlay();
		}
	}
	void Level::Tick(float deltaTime)
	{
		// Actor에 이벤트를 흘린다
		for (Actor* actor : actors)
		{
			actor->Tick(deltaTime);
		}

	}
	void Level::Draw()
	{
		// Actor에 이벤트를 흘린다
		for (Actor* actor : actors)
		{
			actor->Draw();
		}
	}
	void Level::AddNewActor(Actor* newActor)
	{
		// TODO: 프레임 처리(고정)를 고려하여 나중에 따로 추가적인 작업을 해야함
		// push_back은 매개변수를 l-value로서 처리를 한다
		// actors.push_back(newActor);
		actors.emplace_back(newActor);
	}
}