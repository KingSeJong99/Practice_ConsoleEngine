#pragma once

// 4251 메시지를 차단한다!
#pragma warning(disable: 4251)

// STL(Standard Tamplate Library - C++에서 기본적으로 제공하는 라이브러리)
// 크기가 알아서 변경되는 동적배열
#include<vector>
#include"common/RTTI.h"


namespace Mint
{
	// Actor 클래스 전방선언
	class Actor;
	// 역할 : 레벨에 있는 모든 물체(Actor)를 관리한다.
	class MINT_API Level : public RTTI
	{
		RTTI_DECLARATIONS(Level, RTTI)

	public:
		Level();
		virtual ~Level();

		// 게임 플레이 이벤트
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// 액터 추가 함수
		void AddNewActor(Actor* newActor);

	protected:
		// 액터 배열을 추가한다
		std::vector<Actor*> actors;
	};

}
