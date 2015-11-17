#pragma once

#include <GL/glew.h>
#include <SDL/SDL.h>

enum class GameState {PLAY, EXIT};

class MainGame
{
	public:
		MainGame();
		~MainGame();

		void run();

	private:
		void initSystems();
		void gameLoop();
		void processInput();

		SDL_Window* _window; // _ since it is private
		int _screenWidth;
		int _screenHeight;
		GameState _gameState;
};

