#ifndef TOMENGINE_SPRITE_RENDERER_HPP
#define TOMENGINE_SPRITE_RENDERER_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Entity/SpriteEntity.hpp"

namespace tomengine
{

class SpriteRenderer
{
public:
    SpriteRenderer();
    ~SpriteRenderer();

    void DrawSprite(SpriteEntityPtr pEntity);

private:
    ShaderPtr shader;
    GLuint vao;

    void InitRenderData();
    void InitShader();
};

} // namespace tomengine

#endif