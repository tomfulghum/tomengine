#include "ResourceManager.hpp"
#include "Sprite.hpp"

using namespace tomengine;

Sprite::Sprite(const std::string& pTexture, const glm::vec3& pTint) :
    tint(pTint)
{
    this->texture = ResourceManager::GetTexture2D(pTexture);
}

Sprite::Sprite(Texture2DPtr pTexture, const glm::vec3& pTint) :
    tint(pTint)
{
    this->texture = pTexture;
}

void Sprite::SetTint(const glm::vec3& pTint)
{
    this->tint = pTint;
}