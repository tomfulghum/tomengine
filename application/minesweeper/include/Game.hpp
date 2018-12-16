#ifndef MINESWEEPER_GAME_HPP
#define MINESWEEPER_GAME_HPP

#include "Grid.hpp"

enum GameState {
    PLAYING,
    WIN,
    LOSE
};

class Game
{
public:
    static GridPtr grid;
    static int squareCount;
    static int mineCount;
    static int openSquares;

    static bool IsPlaying() { return state == PLAYING; }
    static void Reset();
    static void Lose();

    static void UpdateGameState();

private:
    static GameState state;
    static bool gameOver;
};

#endif