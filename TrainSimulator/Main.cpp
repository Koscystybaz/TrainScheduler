#include "Loop.h"

int main(int argc, char* args[])
{
	Loop* loop = nullptr;

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	loop = new Loop();
	loop->Init("Train SImulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, false);

	while (loop->Running()) {

		frameStart = SDL_GetTicks();

		loop->HandleEvents();
		loop->Uptade();
		loop->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	loop->Clean();

	return 0;
}