#ifndef TOMENGINE_SPRITE_HPP
#define TOMENGINE_SPRITE_HPP

#include <memory>
#include <string>

#include "ResourceManager.hpp"
#include "Texture2D.hpp"

namespace tomengine
{

class Sprite;
typedef std::shared_ptr<Sprite> SpritePtr;
typedef std::weak_ptr<Sprite> SpritePtrW;

class Sprite
{
public:
    Sprite(const std::string& pTexture, const glm::vec3& pTint = glm::vec3(1.0f));
    Sprite(Texture2DPtr pTexture, const glm::vec3& pTint = glm::vec3(1.0f));

    Texture2DPtr GetTexture() { return this->texture; }
    glm::vec3 GetTint() { return this->tint; }
    void SetTint(const glm::vec3& pTint);

private:
    Texture2DPtr texture;
    glm::vec3 tint;
};

} // namespace tomengine

#endif