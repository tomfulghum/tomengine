#ifndef TOMENGINE_SPRITE_RENDERER_HPP
#define TOMENGINE_SPRITE_RENDERER_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Entity/SpriteEntity.hpp"

namespace tomengine
{

class SpriteRenderer;
typedef std::shared_ptr<SpriteRenderer> SpriteRendererPtr;
typedef std::weak_ptr<SpriteRenderer> SpriteRendererPtrW;

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