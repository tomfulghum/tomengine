#ifndef TOMENGINE_SPRITE_HPP
#define TOMENGINE_SPRITE_HPP

#include <string>

#include <glm/glm.hpp>

#include "Common.hpp"

namespace tomengine
{

class Sprite
{
public:
    Sprite(const std::string& texture, const glm::vec3& tint = glm::vec3(1.0f));
    Sprite(Texture2DPtr texture, const glm::vec3& tint = glm::vec3(1.0f));

    Texture2DPtr GetTexture() const { return this->texture; }
    glm::vec3 GetTint() const { return this->tint; }

    void SetTint(const glm::vec3& tint);

private:
    Texture2DPtr texture;
    glm::vec3 tint;
};

} // namespace tomengine

#endif