#pragma once

namespace Mint
{
	// Main game engine class.
	class Engine
	{
		// 데이터
		// down(누르기), up(떼기), hold(유지)
		struct KeyState
		{
			// 현재 키가 눌렸는가?
			bool isKeyDown = false;

			// 이전에 키가 눌렸었는가?
			bool wasKeyDown = false;
		};

	public:

		Engine();
		~Engine();

		// 엔진 루프(게임 루프)
		void Run();
		
		// 엔진 종료 함수
		void QuitEngine();

		// 입력을 확인하는 함수들
		// 이전에 입력이 안됐지만 현재 입력이 됐으면 한 번 호출한다
		bool GetKeyDown(int keyCode);

		// 이전에 입력이 됐었지만 현재 입력이 취소됐으면 한 번 호출한다
		bool GetKeyUp(int keyCode);

		// 현재 눌려있으면 반복적으로 호출한다
		bool GetKey(int keyCode);

	private:
		// 입력 처리 함수
		void ProcessInput();

		// 업데이트 함수.
		void Tick(float deltaTime);

		// 그리기 함수. (Draw/Render).
		void Draw();

		// 엔진 종료 플래그
		bool isQuit = false;

		// 키 상태 저장용 배열
		KeyState keyStates[255] = { };
	};
}


