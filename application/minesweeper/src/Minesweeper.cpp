#include "Minesweeper.hpp"

#include <iostream>

#include "Environment.hpp"

using namespace tomengine;

Minesweeper::Minesweeper() :
    Application()
{
}

Minesweeper::~Minesweeper()
{
}

void Minesweeper::Initialize()
{

    std::cout << "Initialize Minesweeper!" << std::endl;
}

void Minesweeper::Update()
{
    std::cout << "Update Minesweeper!" << std::endl;
}

void Minesweeper::Render()
{
    std::cout << "Render Minesweeper!" << std::endl;
}

void Minesweeper::Terminate()
{
    std::cout << "Terminate Minesweeper!" << std::endl;
}

int main(int argc, char const* argv[])
{
    ApplicationPtr game = std::make_shared<Minesweeper>();
    Environment::SetApplication(game);
    Environment::SetWindowTitle("Minesweeper");

    Environment::Initialize();
    Environment::Update();
    Environment::Terminate();

    return 0;
}