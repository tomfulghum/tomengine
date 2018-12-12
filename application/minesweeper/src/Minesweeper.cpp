#include "Minesweeper.hpp"

#include <iostream>
#include <cmath>
#include <memory>

#include <glm/glm.hpp>

#include "Entity.hpp"
#include "Environment.hpp"
#include "Input.hpp"
#include "ResourceManager.hpp"
#include "Component/SpriteRenderer.hpp"
#include "Texture2D.hpp"
#include "Time.hpp"
#include "Transformable.hpp"

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

Texture2DPtr texMegumin;
EntityPtr entMegumin;
//SpriteEntityPtr entMegumin;
//SpriteRendererPtr spriteRenderer;
//GridPtr grid;
//GridRenderer* gridRenderer;
float rot = 0.0f;
float scale = 0.0f;

void Minesweeper::Initialize()
{
    std::cout << "Initialize Minesweeper!" << std::endl;
    Environment::SetWindowTitle("Minesweeper");
    Environment::SetWindowDimensions(1280, 960);

    entMegumin = std::make_shared<Entity>();
    texMegumin = ResourceManager::LoadTexture2D("data/sprite/megumin.png", "Sprite_Megumin");
    SpritePtr spriteMegumin = std::make_shared<Sprite>(texMegumin);
    entMegumin->AddComponent<SpriteRenderer>(spriteMegumin);
    entMegumin->GetComponent<SpriteRenderer>().SetAnchorPosition(ANCHOR_MIDDLE);
    entMegumin->SetScale(texMegumin->GetWidth() * 0.5f, texMegumin->GetHeight() * 0.5f);

    /*
    grid = std::make_shared<Grid>(16, 16);
    grid->Generate(40);
    grid->Visualize();

    gridRenderer = new GridRenderer(spriteRenderer);
    */
}

void Minesweeper::Update()
{
    float xPos = Environment::WindowWidth() / 2.0f + (200.0f * std::sin(Time::RunTime()));
    float yPos = Environment::WindowHeight() / 2.0f + (200.0f * -std::cos(Time::RunTime()));
    entMegumin->SetPosition(xPos, yPos);
    entMegumin->SetRotation(rot += 100.0f * Time::DeltaTime());
    //entMegumin->SetScale(glm::vec3(texMegumin->GetWidth(), texMegumin->GetHeight(), 0.0f) * (scale += 0.1f * Time::DeltaTime()));
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