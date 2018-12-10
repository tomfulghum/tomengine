#ifndef TOMENGINE_SPRITE_RENDERER_HPP
#define TOMENGINE_SPRITE_RENDERER_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Common.hpp"
#include "Component/Component.hpp"

namespace tomengine
{

class SpriteRenderer : public Component
{
    COMPONENT_DECLARATION(SpriteRenderer)

public:
    SpriteRenderer();
    SpriteRenderer(SpritePtr sprite);

    void SetSprite(SpritePtr sprite);

    void Update() override {}
    void Render() override;

private:
    SpritePtr sprite;
    ShaderPtr shader;
    unsigned int vao;

    void InitRenderData();
    void InitShader();
};

} // namespace tomengine

#endif