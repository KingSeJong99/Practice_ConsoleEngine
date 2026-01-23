#include"Engine.h"
#include<iostream>
#include<Windows.h>

namespace Mint
{
	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
	}

	void Engine::Run()
	{
		// cpu의 주파수로 초를 구하기.
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);

		// 프레임 계산용 변수
		int64_t currentTime = 0;
		int64_t previousTime = 0;

		// 하드웨어 타이머로 시간 구하기
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);

		// 엔진 시작 직전이므로 두 시간 값은 동일하게 초기화되어있다
		currentTime = time.QuadPart;
		previousTime = currentTime;

		// 기준 프레임(단위를 초로)
		float targetFrameRate = 15.0f;
		float oneFrameTime = 1.0f / targetFrameRate;

		// 엔진 루프(게임루프)
		while (!isQuit)
		{
			// 현재 시간 구하기
			QueryPerformanceCounter(&time);
			currentTime = time.QuadPart;

			// 프레임 시간 계산
			float deltaTime
				= static_cast<float>(currentTime - previousTime);

			deltaTime = deltaTime
				/ static_cast<float>(frequency.QuadPart);

			// 고정 프레임 기법
			if (deltaTime >= oneFrameTime)
			{
				ProcessInput();

				// 프레임 처리 !!
				// Tick(1.0f / 60.0f);
				Tick(deltaTime);
				Draw();
				// 이전 시간 값 갱신하기
				previousTime = currentTime;

				// 현재 입력 값을 이전 입력 값으로 저장한다
				// 키 마다 입력을 읽는다
				// (중요)운영체제가 제공하는 기능을 사용할 수 밖에 없다 !!
				for (int ix = 0; ix < 255; ++ix)
				{
					keyStates[ix].isKeyDown
						= keyStates[ix].isKeyDown;
				}
			}
		}

		// TODO: 정리 작업 (언젠가)
		std::cout << "엔진이 죽고 말았다....\n";
	}
	void Engine::QuitEngine()
	{
		isQuit = true;
	}

	bool Engine::GetKeyDown(int keyCode)
	{
		return keyStates[keyCode].isKeyDown
			&& !keyStates[keyCode].wasKeyDown;
	}

	bool Engine::GetKeyUp(int keyCode)
	{
		return !keyStates[keyCode].isKeyDown
			&& keyStates[keyCode].wasKeyDown;
	}

	bool Engine::GetKey(int keyCode)
	{
		return keyStates[keyCode].isKeyDown;
	}

	void Engine::ProcessInput()
	{
		// 키 마다 입력을 읽는다
		// (중요)운영체제가 제공하는 기능을 사용할 수 밖에 없다 !!
		for (int ix = 0; ix < 255; ++ix)
		{
			keyStates[ix].wasKeyDown
				= GetAsyncKeyState(ix) & 0x8000 > 0 ? true : false;
		}
	}
	void Engine::Tick(float deltaTime)
	{
		std::cout
			<< "DeltaTime: " << deltaTime
			<< ", FPS: " << (1.0f / deltaTime) << "\n";

		// ESC키를 누르면 종료한다
		if (GetKeyDown(VK_ESCAPE))
		{
			QuitEngine();
		}
	}
	void Engine::Draw()
	{
	}
}