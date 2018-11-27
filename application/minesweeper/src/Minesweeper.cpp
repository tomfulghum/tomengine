#include "Minesweeper.hpp"

#include <iostream>
#include <memory>

#include "Environment.hpp"
#include "ResourceManager.hpp"
#include "SpriteRenderer.hpp"
#include "Entity/SpriteEntity.hpp"

using namespace tomengine;

Minesweeper::Minesweeper() :
    Application()
{
}

Minesweeper::~Minesweeper()
{
}

SpriteEntityPtr entMegumin;
SpriteRendererPtr spriteRenderer;

void Minesweeper::Initialize()
{
    Texture2DPtr texMegumin = ResourceManager::LoadTexture2D("data/sprite/megumin.png", "Sprite_Megumin");
    entMegumin = std::make_shared<SpriteEntity>(texMegumin);
    spriteRenderer = std::make_shared<SpriteRenderer>();

    std::cout << "Initialize Minesweeper!" << std::endl;
}

void Minesweeper::Update()
{
    //std::cout << "Update Minesweeper!" << std::endl;
}

void Minesweeper::Render()
{
    spriteRenderer->DrawSprite(entMegumin);
    //std::cout << "Render Minesweeper!" << std::endl;
}

void Minesweeper::Terminate()
{
    spriteRenderer.reset();
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