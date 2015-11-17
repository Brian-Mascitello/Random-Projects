#include "MainGame.h"

#include <iostream>

MainGame::MainGame()
{
	_window = nullptr;
	// hard coded for now
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}


MainGame::~MainGame()
{
}

void MainGame::run() {
	initSystems();
	gameLoop();
}

void MainGame::initSystems() {
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}

void MainGame::gameLoop() {
	// This is where the main game is going to happen.

	while (_gameState != GameState::EXIT) {
		processInput();
	}
}

void MainGame::processInput() {
	SDL_Event myevent;

	while (SDL_PollEvent(&myevent)) {
		switch (myevent.type) {
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;

			case SDL_MOUSEMOTION:
				std::cout << myevent.motion.x << " " << myevent.motion.y << std::endl;
				break;
		}
	}
}