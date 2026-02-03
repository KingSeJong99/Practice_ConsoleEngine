#include<iostream>
#include"Engine/Engine.h"
#include"Game/Game.h"
#include"Level/SokobanLevel.h"

using namespace Mint;

//260203
// 예시 배열
// CHAR_INFO charArray[3*3] = { };
// charArray[2*3 + 1].Char.AsciiChar = 'P';
// charArray[2*3 + 1].Attributes = FOREGROUND_GREEN;
// 
// charArray[0*0 + 1].Char.AsciiChar = '#';
// charArray[0*0 + 1].Attributes = FOREGROUND_RED;
// ㅁ
// 
// const int width = 3;
// const int height = 3;
// 
// COORD position = {};
// COORD screenSize;
// screenSize.X = width;
// screenSize.Y = height;
// 
// SMALL_RECT wroteRegopn{
// 0,
// 0,
// static_case<short>(width),
// static_cat<short>(height)
// };
// 
// WriteConsoleOutputA(
// GetStdHandle(STD_OUTPUT_HANDLE),
// charArray, 
// screenSize,
// position,
// &writeReion
// );
// 
// CreateConsoleScreenBuffer()
// // SetConsoleActiveScreenBuffer();
//



int main()
{
	// Mint::Engine engine; 
	// engine.SetNewLevel(new SokobanLevel());
	// engine.Run();

	Game game;
	game.Run();
}