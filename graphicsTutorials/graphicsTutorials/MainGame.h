#pragma once

#include <GL/glew.h>
#include <SDL/SDL.h>

class MainGame
{
	public:
		MainGame();
		~MainGame();

		void run();

		void initSystems();

	private:
		SDL_Window* _window; // _ since it is private
		int _screenWidth;
		int _screenHeight;
};

