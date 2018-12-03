#include "Minesweeper.hpp"

#include <iostream>
#include <memory>

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "Environment.hpp"
#include "Input.hpp"
#include "ResourceManager.hpp"
#include "SpriteRenderer.hpp"
#include "Time.hpp"
#include "Transformable.hpp"
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
float rot = 0.0f;

void Minesweeper::Initialize()
{
    std::cout << "Initialize Minesweeper!" << std::endl;

    Texture2DPtr texMegumin = ResourceManager::LoadTexture2D("data/sprite/megumin.png", "Sprite_Megumin");
    entMegumin = std::make_shared<SpriteEntity>(texMegumin);
    spriteRenderer = std::make_shared<SpriteRenderer>();
}

void Minesweeper::Update()
{
    entMegumin->SetPosition(Environment::WindowWidth() / 2.0f, Environment::WindowHeight() / 2.0f);
    entMegumin->SetRotation(rot += Time::DeltaTime());

    std::cout << glm::to_string(Input::GetCursorPosition()) << std::endl;
    //std::cout << entMegumin->GetRotation() << std::endl;
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

    Environment::Initialize();

    Environment::SetWindowDimensions(800, 600);
    Environment::SetWindowTitle("Minesweeper");

    Environment::Update();
    Environment::Terminate();

    return 0;
}