#include <iostream>
#include "MainGame.h"

/*
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <Windows.h>
*/

int main(int argc, char** argv) {

	MainGame mainGame;
	mainGame.run();

	std::cout << "Enter any key to quit...";
	int a;
	std::cin >> a;
	return 0;

	/*
	SDL_Init(SDL_INIT_EVERYTHING);

	return 0;
	*/
}