#include "SpriteEntity.hpp"

using namespace tomengine;

SpriteEntity::SpriteEntity(SpritePtr pSprite) :
    Entity(), sprite(pSprite)
{
    InitializeTransform();
}

SpriteEntity::SpriteEntity(Texture2DPtr pTexture) :
    Entity()
{
    this->sprite = std::make_shared<Sprite>(pTexture, glm::vec3(1.0f));
    InitializeTransform();
}

void SpriteEntity::InitializeTransform()
{
    int spriteWidth = this->sprite->GetTexture()->GetWidth();
    int spriteHeight = this->sprite->GetTexture()->GetHeight();

    //this->SetPivot(glm::vec3(0.5f * spriteWidth, 0.5f * spriteHeight, 0.0f));
    this->SetScale(glm::vec3(spriteWidth, spriteHeight, 1.0f));
}