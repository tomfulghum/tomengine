#ifndef TOMENGINE_SPRITE_HPP
#define TOMENGINE_SPRITE_HPP

#include <string>

#include "ResourceManager.hpp"
#include "Texture2D.hpp"
#include "Transformable.hpp"

namespace tomengine
{
    class Sprite : public Transformable
    {
        public:
        Sprite(const std::string &pTexture, const glm::vec3 &pTint = glm::vec3(1.0f));
        Sprite(Texture2D &pTexture, const glm::vec3 &pTint = glm::vec3(1.0f));

        glm::vec3 GetTint() { return this->tint; } 
        void SetTint(const glm::vec3 &pTint);

        private:
        Texture2D texture;
        glm::vec3 tint;
    };
} // tomengine

#endif