#include"SokobanLevel.h"
#include"Actor/Player.h"
#include"Actor/Wall.h"
#include"Actor/Ground.h"
#include"Actor/Box.h"
#include"Actor/Target.h"
#include"Util/Util.h"

#include<iostream>

/*
* # : 벽(wall)
* . : 바닥(gruond)
* p : 플레이어(player)
* b : 박스(box)
* t : 타겟(target)
##########
#........#
#........#
#..p..b..#
#.....b..#
#........#
#........#
#......t.#
#......t.#
##########
*/

SokobanLevel::SokobanLevel()
{
	// TestActor 액터를 레벨에 추가
	// AddNewActor(new Player());
	//LoadMap("../Assets/Map.txt");
	LoadMap("../Assets/stage1.txt");
}
void SokobanLevel::Draw()
{
	super::Draw();
	
	// 게임 클리어인 경우 메시지 출력하기
	if (isGameClear)
	{
		// 콘솔 위치 및 생상 설정
		Util::SetConsolePosition(Vector2(30, 0));
		Util::SetConsoleTextColor(Color::White);

		// 게임 클리어 메시지 출력하기
		std::cout << "Game Clear!";
	}
}
void SokobanLevel::LoadMap(const char* filename)
{
	// 파일을 로드한다
	// 최종 파일 경로를 만든다
	char path[2048] = {};
	sprintf_s(path, 2048, "../Assets/%s", filename);

	// 파일 열기
	FILE* file = nullptr;
	fopen_s(&file, path, "rt");

	// 예외 처리
	if (!file)
	{
		// 표준 오류 콘솔 활용하기
		std::cerr << "Failed to open map file.\n";
		
		// 디버그 모드에서 중단점을 걸어준다
		__debugbreak();
	}

	// 맵 읽기
	// 
	// 맵 크기 파악하기(파일의 포지션 포인터를 파일의 끝으로 이동시킨다)
	fseek(file, 0, SEEK_END);

	// 이동시킨 위치를 읽는다
	size_t fileSize = ftell(file);

	// File Position을 처음으로 되돌린다
	rewind(file);
	
	// 파일에서 데이터를 읽어올 버퍼를 생성한다
	char* data = new char[fileSize + 1];

	// 데이터 읽이오기
	size_t readSize = fread(data, sizeof(char), fileSize, file);

	// 읽어온 문자열을 파싱(분석)하여 출력한다!
	int index = 0;

	// 객체를 생성할 위치 값
	Mint::Vector2 position;


	while (true)
	{
		if (index >= fileSize)
		{
			break;
		}

		// 캐릭터 읽기
		char mapChracter = data[index];
		++index;

		// 개행 문자 처리하기
		if (mapChracter == '\n')
		{
			// y 좌표를 하나 늘리고 x 좌표를 초기화한다
			++position.y;
			position.x = 0;
			continue;
		}

		/*
		*# : 벽(wall)
		* . : 바닥(gruond)
		* p : 플레이어(player)
		* b : 박스(box)
		* t : 타겟(target)
		*/
		switch (mapChracter)
		{
		case '#':
		case '1':
			// std::cout << "#";
			AddNewActor(new Wall(position));
			break;
		case '.':
			// std::cout << " ";
			AddNewActor(new Ground(position));
			break;
		case'p':
			AddNewActor(new Player(position));
			AddNewActor(new Ground(position));
			// std::cout << "P";
			break;
		case'b':
			// std::cout << "B";
			AddNewActor(new Box(position));
			AddNewActor(new Ground(position));
			break;
		case't':
			// std::cout << "T";
			AddNewActor(new Target(position));
			++targetScore;
			break;
		}

		// x 좌표를 증가한다
		++position.x;

	}

	// 사용한 버퍼를 해제한다
	delete[] data;

	// 파일이 정상적으로 열렸으면 닫는다
	fclose(file);
}

bool SokobanLevel::CanMove(
	const Mint::Vector2& playerPosition, 
	const Mint::Vector2& nextPosition)
{
	// 레벨에 있는 박스 Actor 모으기
	// 박스는 플레이어가 밀기 등 추가적으로 처리해야한다
	std::vector<Actor*> boxes;
	
	// 레벨에 배치된 전체 액터를 순회하면서 박스 찾기
	for (Actor* const actor : actors)
	{
		// 액터가 박스 타입인지 확인한다
		if (actor->IsTypeOf<Box>())
		{
			boxes.emplace_back(actor);
			continue;
		}
	}

	// 이동하려는 위치에 박스가 있는지 확인
	
	Actor* boxActor = nullptr;
	for (Actor* const box : boxes)
	{
		// 위치 비교하기
		if (box->GetPosition() == nextPosition)
		{
			boxActor = box;
			break;
		}
	}

	// 경우의 수 처리
	// 이동하려는 곳에 박스가 있는 경우
	if (boxActor)
	{
		// #1 : 박스를 옮기려는 곳에 다른 박스가 있는지 확인한다
		// 두 위치 사이에서 이동 방향을 구한다 (벡터의 뺄셈 활용하기)
		// 이동 로직에서 두 벡터를 더하는 것은 둘 중 하나는 위치이고 다른 하나는 벡터임을 의미한다!
		// 수학적으로 위치의 합은 존재가 불가능함!!
		Vector2 direction = nextPosition - playerPosition;
		Vector2 newPosition = boxActor->GetPosition() + direction;

		// 검색하기
		for (Actor* const otherBox : boxes)
		{
			// 앞에서 검색한 박스와 같다면 건너뛴다
			if (otherBox == boxActor)
			{
				continue;
			}

			// 다른 박스가 있는지 확인하기
			if (otherBox->GetPosition() == newPosition)
			{
				// 두 개의 박스가 겹쳐진 방향으로는 이동이 불가능하다!
				return false;
			}
		}

		// 검색하기
		for (Actor* const actor : actors)
		{
			if (actor->GetPosition() == newPosition)
			{
				// 벽이라면 이동이 불가능하다..
				if (actor->IsTypeOf<Wall>())
				{
					return false;
				}

				// ground or target이라면 이동이 가능하다!
				if (actor->IsTypeOf<Ground>() ||
					actor->IsTypeOf<Target>())
				{
					// 박스의 이동처리
					boxActor->SetPosition(newPosition);

					// 게임 점수 확인하기
					isGameClear = CheckGameClear();

					// 플레이어 이동 가능
					return true;
				}
			}	
		}
	}


	// 이동하려는 곳에 박스가 없는 경우
	// -> 이동하려는 곳에 있는 액터가 벽이 아니면 이동이 가능하다
	for (Actor* const actor : actors)
	{
		// 먼저 이동하려는 위치에 있는 액터를 검색한다
		if (actor->GetPosition() == nextPosition)
		{
			// 이 액터가 벽인지 확인한다
			if (actor->IsTypeOf<Wall>())
			{
				return false;
			}

			// ground or target
			return true;
		}
	}

	// return false;

	return false;
}

bool SokobanLevel::CheckGameClear()
{
	// 타겟 위에 있는 박스의 수 검증하기
	int currentScore = 0;
	
	// 벡터에 박스 및 타겟 저장하기
	std::vector<Actor*> boxes;
	std::vector<Actor*> targets;

	// 레벨에 배치된 배열을 순회하면서 두 액터를 필터링하기
	for (Actor* const actor : actors)
	{
		// 박스인 경우 박스 배열에 추가한다
		if (actor->IsTypeOf<Box>())
		{
			boxes.emplace_back(actor);
			continue;
		}

		// 타겟의 경우 타겟 배열에 추가하기
		if (actor->IsTypeOf<Target>())
		{
			targets.emplace_back(actor);
		}
	}

	// 점수 확인하기( 박스의 위치가 타겟의 위치와 같은가?)
	for (Actor* const box : boxes)
	{
		for (Actor* const target : targets)
		{
			if (box->GetPosition() == target->GetPosition())
			{
				currentScore += 1;
			}
		}
	}

	return currentScore == targetScore;
}
