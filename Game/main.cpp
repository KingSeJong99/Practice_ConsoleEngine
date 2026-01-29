#include<iostream>
#include"Engine/Engine.h"
#include"Level/TestLevel.h"

using namespace Mint;

int main()
{
	Mint::Engine engine; 
	engine.SetNewLevel(new TestLevel());
	engine.Run();
}