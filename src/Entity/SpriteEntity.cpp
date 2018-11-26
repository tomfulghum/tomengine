#include "Entity/SpriteEntity.hpp"

using namespace tomengine;

SpriteEntity::SpriteEntity(SpritePtr pSprite, ShaderPtr pShader) :
    Entity(), sprite(pSprite), shader(pShader)
{
    InitializeTransform();
}

SpriteEntity::SpriteEntity(Texture2DPtr pTexture, ShaderPtr pShader) :
    Entity(), shader(pShader)
{
    this->sprite = std::make_shared<Sprite>(pTexture, glm::vec3(1.0f));
    InitializeTransform();
}

void SpriteEntity::InitializeTransform()
{
    int spriteWidth = this->sprite->GetTexture()->GetWidth();
    int spriteHeight = this->sprite->GetTexture()->GetHeight();

    this->transform.pivot = glm::vec3(0.5f * spriteWidth, 0.5f * spriteHeight, 0.0f);
}