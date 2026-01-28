#include<iostream>
#include"Engine/Engine.h"
#include"Level/TestLevel.h"
#include"Actor/TestActor.h"

using namespace Mint;

int main()
{
	// Mint::Engine engine; 
	// engine.SetNewLevel(new TestLevel());
	// engine.Run();

	TestLevel* level = new TestLevel();
	Actor* actor = new Actor();
	TestActor* testActor = new TestActor();

	// if (actor->Is(testActor))
	// {
	// 	std::cout << "actor is TestActor Type\n";
	// }
	// else
	// {
	// 	std::cout << "actor is not TestActor Type\n";
	// }


	// TestActor* testActor2 = dynamic_cast<TestActor*>(actor);

	// dynamic_cast와 같은 결과임.
	TestActor* testActor = actor->As<TestActor>();
	if (testActor)
	{
		std::cout << "actor is TestActor type.\n";
	}
	else
	{
		std::cout << "actor is not TestActor type.\n";
	}
}