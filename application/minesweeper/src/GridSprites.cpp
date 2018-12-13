#include "GridSprites.hpp"

#include <vector>

#include "Common.hpp"
#include "ResourceManager.hpp"
#include "Texture2D.hpp"

using namespace tomengine;

std::vector<SpritePtr> GridSprites::sprites;
bool GridSprites::initialized = false;

void GridSprites::Load()
{
    Texture2DPtr texNode = ResourceManager::LoadTexture2D("data/sprite/node.png", "sprite_node");
    Texture2DPtr texNodeFlagged = ResourceManager::LoadTexture2D("data/sprite/node_flagged.png", "Sprite_node_flagged");
    Texture2DPtr texNodeOpen1 = ResourceManager::LoadTexture2D("data/sprite/node_open_1.png", "Sprite_node_open_1");
    Texture2DPtr texNodeOpen2 = ResourceManager::LoadTexture2D("data/sprite/node_open_2.png", "Sprite_node_open_2");
    Texture2DPtr texNodeOpen3 = ResourceManager::LoadTexture2D("data/sprite/node_open_3.png", "Sprite_node_open_3");
    Texture2DPtr texNodeOpen4 = ResourceManager::LoadTexture2D("data/sprite/node_open_4.png", "Sprite_node_open_4");
    Texture2DPtr texNodeOpen5 = ResourceManager::LoadTexture2D("data/sprite/node_open_5.png", "Sprite_node_open_5");
    Texture2DPtr texNodeOpen6 = ResourceManager::LoadTexture2D("data/sprite/node_open_6.png", "Sprite_node_open_6");
    Texture2DPtr texNodeOpen7 = ResourceManager::LoadTexture2D("data/sprite/node_open_7.png", "Sprite_node_open_7");
    Texture2DPtr texNodeOpen8 = ResourceManager::LoadTexture2D("data/sprite/node_open_8.png", "Sprite_node_open_8");
    Texture2DPtr texNodeOpenBlank = ResourceManager::LoadTexture2D("data/sprite/node_open_blank.png", "Sprite_node_open_blank");
    Texture2DPtr texNodeOpenMineClicked = ResourceManager::LoadTexture2D("data/sprite/node_open_mine_clicked.png", "Sprite_node_open_mine_clicked");
    Texture2DPtr texNodeOpenMine = ResourceManager::LoadTexture2D("data/sprite/node_open_mine.png", "Sprite_node_open_mine");

    sprites.push_back(std::make_shared<Sprite>(texNode));
    sprites.push_back(std::make_shared<Sprite>(texNodeFlagged));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpen1));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpen2));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpen3));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpen4));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpen5));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpen6));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpen7));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpen8));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpenBlank));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpenMineClicked));
    sprites.push_back(std::make_shared<Sprite>(texNodeOpenMine));

    initialized = true;
}

SpritePtr GridSprites::GetSprite(NodeState pState)
{
    if (initialized)
    {
        return sprites[pState];
    }
    else
    {
        return nullptr;
    }
}

bool GridSprites::IsInitialized()
{
    return initialized;
}