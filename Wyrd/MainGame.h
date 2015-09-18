#ifndef MAINGAME_H
#define MAINGAME_H

#include <SDL/SDL.h>

enum class EGameState
{
	PLAY,
	EXIT
};

class MainGame
{
public:
	MainGame();

	~MainGame()
	{
	}

	void Run();

private:
	void InitializeComponents();
	void GameLoop();
	void ProcessInput();

	SDL_Window* m_window;
	EGameState	m_gameState;

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const char* WINDOW_TITLE = "Wyrd Development Build 1.0.0";
};

#endif
