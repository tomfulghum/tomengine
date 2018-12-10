#include "Minesweeper.hpp"

#include <iostream>
#include <memory>

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "Environment.hpp"
#include "Input.hpp"
#include "ResourceManager.hpp"
#include "Component/SpriteRenderer.hpp"
#include "Time.hpp"
#include "Transformable.hpp"
#include "SpriteEntity.hpp"

#include "Grid.hpp"
#include "GridRenderer.hpp"

using namespace tomengine;

Minesweeper::Minesweeper() :
    Application()
{
}

Minesweeper::~Minesweeper()
{
}

EntityPtr entMegumin;
//SpriteEntityPtr entMegumin;
//SpriteRendererPtr spriteRenderer;
//GridPtr grid;
//GridRenderer* gridRenderer;
float rot = 0.0f;

void Minesweeper::Initialize()
{
    std::cout << "Initialize Minesweeper!" << std::endl;
    Environment::SetWindowTitle("Minesweeper");
    Environment::SetWindowDimensions(800, 600);

    entMegumin = std::make_shared<Entity>();
    Texture2DPtr texMegumin = ResourceManager::LoadTexture2D("data/sprite/megumin.png", "Sprite_Megumin");
    SpritePtr spriteMegumin = std::make_shared<Sprite>(texMegumin);
    entMegumin->AddComponent<SpriteRenderer>();
    entMegumin->GetComponent<SpriteRenderer>().SetSprite(spriteMegumin);

    /*
    grid = std::make_shared<Grid>(16, 16);
    grid->Generate(40);
    grid->Visualize();

    gridRenderer = new GridRenderer(spriteRenderer);
    */
}

void Minesweeper::Update()
{
    entMegumin->SetPosition(Environment::WindowWidth() / 2.0f, Environment::WindowHeight() / 2.0f);
    entMegumin->SetRotation(rot += 10.0f * Time::DeltaTime());

    //std::cout << glm::to_string(Input::GetCursorPosition()) << std::endl;
    //std::cout << entMegumin->GetRotation() << std::endl;
    //std::cout << "Update Minesweeper!" << std::endl;
}

void Minesweeper::Render()
{
    entMegumin->Render();
    //gridRenderer->Render(grid);
    //std::cout << "Render Minesweeper!" << std::endl;
}

void Minesweeper::Terminate()
{
    std::cout << "Terminate Minesweeper!" << std::endl;
}

int main(int argc, char const* argv[])
{
    ApplicationPtr game = std::make_shared<Minesweeper>();
    Environment::SetApplication(game);

    Environment::Initialize();
    Environment::Run();

    return 0;
}