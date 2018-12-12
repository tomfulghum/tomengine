#ifndef TOMENGINE_SPRITE_RENDERER_HPP
#define TOMENGINE_SPRITE_RENDERER_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Common.hpp"
#include "Component/Component.hpp"

namespace tomengine
{

enum AnchorPosition
{
    ANCHOR_TOPLEFT,
    ANCHOR_BOTTOMLEFT,
    ANCHOR_TOPRIGHT,
    ANCHOR_BOTTOMRIGHT,
    ANCHOR_TOP,
    ANCHOR_BOTTOM,
    ANCHOR_LEFT,
    ANCHOR_RIGHT,
    ANCHOR_MIDDLE
};

class SpriteRenderer : public Component
{
    COMPONENT_DECLARATION(SpriteRenderer)

public:
    SpriteRenderer();
    SpriteRenderer(SpritePtr sprite);

    void SetSprite(SpritePtr sprite);
    void SetAnchorPosition(AnchorPosition anchor);

    void Update() override {}
    void Render() override;

private:
    SpritePtr sprite;
    ShaderPtr shader;
    unsigned int vao;
    bool initialized;

    void InitRenderData();
    void InitShader();
    void InitTexture();
};

} // namespace tomengine

#endif