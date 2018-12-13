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

float rot = 0.0f;
float scale = 0.0f;

void Minesweeper::Initialize()
{
    std::cout << "Initialize Minesweeper!" << std::endl;
    Environment::SetWindowTitle("Minesweeper");
    Environment::SetWindowDimensions(1280, 960);

    entMegumin = std::make_shared<Entity>();
    texMegumin = ResourceManager::LoadTexture2D("data/sprite/brigitte.png", "Sprite_Megumin");
    SpritePtr spriteMegumin = std::make_shared<Sprite>(texMegumin);
    entMegumin->AddComponent<SpriteRenderer>(spriteMegumin);
    entMegumin->GetComponent<SpriteRenderer>().SetAnchorPosition(ANCHOR_MIDDLE);
    entMegumin->SetScale(0.0f, 0.0f);
}

void Minesweeper::Update()
{
    float xPos = Environment::WindowWidth() / 2.0f + (200.0f * std::sin(Time::RunTime()));
    float yPos = Environment::WindowHeight() / 2.0f + (200.0f * -std::cos(Time::RunTime()));
    entMegumin->SetPosition(xPos, yPos);
    entMegumin->SetRotation(rot += 100.0f * Time::DeltaTime());
    entMegumin->SetScale(scale += 0.1f * Time::DeltaTime(), scale);
}

void Minesweeper::Render()
{
    entMegumin->Render();
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