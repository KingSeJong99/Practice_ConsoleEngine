#pragma once

#include"common/RTTI.h"
#include"Math/Vector2.h"

namespace Mint
{
	class MINT_API Actor : public RTTI
	{
		// RTTI 코드 추가
		RTTI_DECLARATIONS(Actor, RTTI)

	public:
		Actor(
			const char image = ' ',
			const Vector2& position = Vector2::Zero
		);
		virtual ~Actor();

		// 게임 플레이 이벤트
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// 위치 변경 및 읽기 함수
		void SetPosition(const Vector2& newPosition);
		inline Vector2 GetPosition() const { return position; }

		// Getter 함수
		inline bool HasBeganPlay() const { return hasBeganPlay; }
		inline bool IsActive() const { return isActive && !destroyRequested; }
		inline bool DestroyRequested() const { return destroyRequested; }
	
	protected:
		// BeginPlay 이벤트가 이미 있는지 확인하는 변수
		bool hasBeganPlay = false;

		// 활성화이 되어있는지 확인하는 변수
		bool isActive = true;

		// 현재 프레임에 삭제 요청을 받았는지 확인하는 변수
		bool destroyRequested = false;

		// 그릴 문자(이미지)
		char image = ' ';

	private:
		// 위치
		Vector2 position;
	};

}
