#include "Minesweeper.hpp"

#include <iostream>
#include <cmath>
#include <memory>

#include <glm/glm.hpp>

#include "EntityManager.hpp"
#include "Environment.hpp"
#include "Input.hpp"
#include "ResourceManager.hpp"
#include "Component/SpriteRenderer.hpp"
#include "Sprite.hpp"
#include "Texture2D.hpp"
#include "Time.hpp"
#include "Transformable.hpp"

#include "Game.hpp"
#include "Grid.hpp"
#include "GridSprites.hpp"

using namespace tomengine;

Minesweeper::Minesweeper() :
    Application()
{
}

Minesweeper::~Minesweeper()
{
}

const int GRID_WIDTH = 9;
const int GRID_HEIGHT = 9;
const int SPRITE_SIZE = 16;
const int MINE_COUNT = 10;

GridPtr grid;

EntityPtr entBorderPanel;
EntityPtr entBorderLeft;
EntityPtr entBorderRight;
EntityPtr entBorderDown;
EntityPtr entCornerLeftUp;
EntityPtr entCornerLeftDown;
EntityPtr entCornerRightUp;
EntityPtr entCornerRightDown;
EntityPtr entInterLeft;
EntityPtr entInterRight;

float rot = 0.0f;
float scale = 0.0f;

void Minesweeper::Initialize()
{
    std::cout << "Initialize Minesweeper!" << std::endl;
    Environment::SetWindowTitle("Minesweeper");
    Environment::SetWindowDimensions(GRID_WIDTH * SPRITE_SIZE + 20, GRID_HEIGHT * SPRITE_SIZE + 56, false);

    SpritePtr sprBorderPanel = std::make_shared<Sprite>(ResourceManager::LoadTexture2D("data/sprite/border_panel.png", "borderPanel"));
    SpritePtr sprBorderVertical = std::make_shared<Sprite>(ResourceManager::LoadTexture2D("data/sprite/border_vertical.png", "borderVert"));
    SpritePtr sprBorderHorizontal = std::make_shared<Sprite>(ResourceManager::LoadTexture2D("data/sprite/border_horizontal.png", "borderHor"));
    SpritePtr sprCornerLeftUp = std::make_shared<Sprite>(ResourceManager::LoadTexture2D("data/sprite/border_corner_leftup.png", "borderCorLU"));
    SpritePtr sprCornerLeftDown = std::make_shared<Sprite>(ResourceManager::LoadTexture2D("data/sprite/border_corner_leftdown.png", "borderCorLD"));
    SpritePtr sprCornerRightUp = std::make_shared<Sprite>(ResourceManager::LoadTexture2D("data/sprite/border_corner_rightup.png", "borderCorRU"));
    SpritePtr sprCornerRightDown = std::make_shared<Sprite>(ResourceManager::LoadTexture2D("data/sprite/border_corner_rightdown.png", "borderCorRD"));
    SpritePtr sprInterLeft = std::make_shared<Sprite>(ResourceManager::LoadTexture2D("data/sprite/border_inter_left.png", "borderIntL"));
    SpritePtr sprInterRight = std::make_shared<Sprite>(ResourceManager::LoadTexture2D("data/sprite/border_inter_right.png", "borderIntR"));

    entBorderPanel = EntityManager::CreateEntity();
    entBorderPanel->AddComponent<SpriteRenderer>();
    entBorderPanel->GetComponent<SpriteRenderer>()->SetSprite(sprBorderPanel);
    entBorderPanel->SetScale(GRID_WIDTH * SPRITE_SIZE + 20, 1.0f);

    entBorderLeft = EntityManager::CreateEntity();
    entBorderLeft->AddComponent<SpriteRenderer>();
    entBorderLeft->GetComponent<SpriteRenderer>()->SetSprite(sprBorderVertical);
    entBorderLeft->SetScale(1.0f, GRID_HEIGHT * SPRITE_SIZE + 56);

    entBorderRight = EntityManager::CreateEntity();
    entBorderRight->AddComponent<SpriteRenderer>();
    entBorderRight->GetComponent<SpriteRenderer>()->SetSprite(sprBorderVertical);
    entBorderRight->SetScale(1.0f, GRID_HEIGHT * SPRITE_SIZE + 56);
    entBorderRight->SetPosition(GRID_WIDTH * SPRITE_SIZE + 10, 0.0f);

    entBorderDown = EntityManager::CreateEntity();
    entBorderDown->AddComponent<SpriteRenderer>();
    entBorderDown->GetComponent<SpriteRenderer>()->SetSprite(sprBorderHorizontal);
    entBorderDown->SetScale(GRID_WIDTH * SPRITE_SIZE + 20, 1.0f);
    entBorderDown->SetPosition(0.0f, GRID_HEIGHT * SPRITE_SIZE + 46);

    entCornerLeftUp = EntityManager::CreateEntity();
    entCornerLeftUp->AddComponent<SpriteRenderer>();
    entCornerLeftUp->GetComponent<SpriteRenderer>()->SetSprite(sprCornerLeftUp);

    entCornerLeftDown = EntityManager::CreateEntity();
    entCornerLeftDown->AddComponent<SpriteRenderer>();
    entCornerLeftDown->GetComponent<SpriteRenderer>()->SetSprite(sprCornerLeftDown);
    entCornerLeftDown->SetPosition(0.0f, GRID_HEIGHT * SPRITE_SIZE + 46);

    entCornerRightUp = EntityManager::CreateEntity();
    entCornerRightUp->AddComponent<SpriteRenderer>();
    entCornerRightUp->GetComponent<SpriteRenderer>()->SetSprite(sprCornerRightUp);
    entCornerRightUp->SetPosition(GRID_WIDTH * SPRITE_SIZE + 10, 0.0f);

    entCornerRightDown = EntityManager::CreateEntity();
    entCornerRightDown->AddComponent<SpriteRenderer>();
    entCornerRightDown->GetComponent<SpriteRenderer>()->SetSprite(sprCornerRightDown);
    entCornerRightDown->SetPosition(GRID_WIDTH * SPRITE_SIZE + 10, GRID_HEIGHT * SPRITE_SIZE + 46);

    entInterLeft = EntityManager::CreateEntity();
    entInterLeft->AddComponent<SpriteRenderer>();
    entInterLeft->GetComponent<SpriteRenderer>()->SetSprite(sprInterLeft);
    entInterLeft->SetPosition(0.0f, 36.0f);

    entInterRight = EntityManager::CreateEntity();
    entInterRight->AddComponent<SpriteRenderer>();
    entInterRight->GetComponent<SpriteRenderer>()->SetSprite(sprInterRight);
    entInterRight->SetPosition(GRID_WIDTH * SPRITE_SIZE + 10, 36.0f);

    GridSprites::Load();

    grid = std::make_shared<Grid>(GRID_WIDTH, GRID_HEIGHT, SPRITE_SIZE);
    grid->SetPosition(10.0f, 46.0f);

    Game::mineCount = MINE_COUNT;
    Game::grid = grid;
    Game::Reset();

    EntityManager::InitEntities();
}

void Minesweeper::Update()
{
    EntityManager::UpdateEntities();
    Game::UpdateGameState();
}

void Minesweeper::Render()
{
    EntityManager::RenderEntities();
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