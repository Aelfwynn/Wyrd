#include "MainGame.h"

#include <iostream>

MainGame::MainGame() : 
m_window(nullptr),
m_gameState(EGameState::PLAY)
{
}

void MainGame::Run()
{
	InitializeComponents();
	GameLoop();
}

void MainGame::InitializeComponents()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	m_window = SDL_CreateWindow(
		WINDOW_TITLE,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
}

void MainGame::GameLoop()
{
	while (m_gameState != EGameState::EXIT)
	{
		ProcessInput();
	}
}

// Hack to output mouse coordinates to console
// For development purposes, should be removed
void OutputMouseCoordinates(const SDL_Event& evnt)
{
	std::cout << "(" << evnt.motion.x << ", " << evnt.motion.y << ")\n";
}

void MainGame::ProcessInput()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			m_gameState = EGameState::EXIT;
			break;

		case SDL_MOUSEMOTION:
			OutputMouseCoordinates(evnt);
			break;
		}
	}
}
