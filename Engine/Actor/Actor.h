#pragma once

#include"common/Common.h"

namespace Mint
{
	class MINT_API Actor
	{
	public:
		Actor();
		virtual ~Actor();

		// 게임 플레이 이벤트
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// Getter 함수
		inline bool HasBeganPlay() const { return hasBeganPlay; }
		bool IsActive() const
		{
			return isActive && !destroyRequested;
		}
	protected:
		// BeginPlay 이벤트가 이미 있는지 확인하는 변수
		bool hasBeganPlay = false;

		// 활성화이 되어있는지 확인하는 변수
		bool isActive = true;

		// 현재 프레임에 삭제 요청을 받았는지 확인하는 변수
		bool destroyRequested = false;
	};

}
