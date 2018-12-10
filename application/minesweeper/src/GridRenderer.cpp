#include "GridRenderer.hpp"

#include "ResourceManager.hpp"

using namespace tomengine;

/*
GridRenderer::GridRenderer(SpriteRendererPtr pSpriteRenderer) :
    spriteRenderer(pSpriteRenderer)
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

    sprites.push_back(std::make_shared<SpriteEntity>(texNode));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeFlagged));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpen1));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpen2));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpen3));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpen4));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpen5));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpen6));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpen7));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpen8));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpenBlank));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpenMineClicked));
    sprites.push_back(std::make_shared<SpriteEntity>(texNodeOpenMine));
}

void GridRenderer::Render(GridPtr pGrid)
{
    spriteRenderer->DrawSprite(sprites[pGrid->GetNode(0, 0).GetState()]);
}
*/