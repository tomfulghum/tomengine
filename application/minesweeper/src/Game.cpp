#include "Game.hpp"

#include <iostream>

#include "Input.hpp"

using namespace tomengine;

GridPtr Game::grid = nullptr;
int Game::squareCount = 0;
int Game::mineCount = 0;
int Game::openSquares = 0;
GameState Game::state = PLAYING;
bool Game::gameOver = false;

void Game::Reset()
{
    state = PLAYING;
    grid->Generate(mineCount);
}

void Game::Lose()
{
    std::cout << "LOSE!" << std::endl;
    gameOver = true;
}

void Game::UpdateGameState()
{
    if (state != PLAYING) {
        if (Input::GetMouseButtonDown(MOUSE_0)) {
            Game::Reset();
        }
    } else {
        if (gameOver) {
            gameOver = false;
            state = LOSE;
        } else if (openSquares == squareCount - mineCount && state == PLAYING) {
            std::cout << "WIN!" << std::endl;
            state = WIN;
        }
    }
}