#include "Entity/SpriteEntity.hpp"

using namespace tomengine;

SpriteEntity::SpriteEntity(SpritePtr pSprite) :
    Entity(), sprite(pSprite)
{
}

SpriteEntity::SpriteEntity(Texture2DPtr pTexture) :
    Entity()
{
    sprite = std::make_shared<Sprite>(pTexture, glm::vec3(1.0f));
}