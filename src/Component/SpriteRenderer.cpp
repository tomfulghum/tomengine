#include "Component/SpriteRenderer.hpp"

#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Environment.hpp"
#include "ResourceManager.hpp"
#include "Shader.hpp"
#include "Sprite.hpp"
#include "Texture2D.hpp"

using namespace tomengine;

COMPONENT_DEFINITION(Component, SpriteRenderer)

SpriteRenderer::SpriteRenderer() :
    Component()
{
    this->initialized = false;
    this->InitRenderData();
    this->InitShader();
}

SpriteRenderer::SpriteRenderer(SpritePtr pSprite) :
    SpriteRenderer()
{
    this->sprite = pSprite;
}

void SpriteRenderer::SetSprite(SpritePtr pSprite)
{
    this->sprite = pSprite;
}

void SpriteRenderer::SetAnchorPosition(AnchorPosition pAnchor)
{
    Texture2DPtr texture = this->sprite->GetTexture();
    EntityPtr ent = this->entity.lock();

    switch (pAnchor) {
        case ANCHOR_TOPLEFT:
            ent->SetPivot(0.0f, 0.0f);
            break;
        case ANCHOR_BOTTOMLEFT:
            ent->SetPivot(0.0f, 1.0f);
            break;
        case ANCHOR_TOPRIGHT:
            ent->SetPivot(1.0f, 0.0f);
            break;
        case ANCHOR_BOTTOMRIGHT:
            ent->SetPivot(1.0f, 1.0f);
            break;
        case ANCHOR_TOP:
            ent->SetPivot(0.5f, 0.0f);
            break;
        case ANCHOR_BOTTOM:
            ent->SetPivot(0.5f, 1.0f);
            break;
        case ANCHOR_LEFT:
            ent->SetPivot(0.0f, 0.5f);
            break;
        case ANCHOR_RIGHT:
            ent->SetPivot(1.0f, 0.5f);
            break;
        case ANCHOR_MIDDLE:
            ent->SetPivot(0.5f, 0.5f);
            break;
    }
}

void SpriteRenderer::Render()
{
    if (this->initialized) {
        this->shader->Use();

        Texture2DPtr texture = this->sprite->GetTexture();
        this->shader->SetMatrix4f("model", this->entity.lock()->GetTransformMatrix());
        this->shader->SetMatrix4f("projection", Environment::OrthoProjectionMatrix());
        this->shader->SetVector3f("tintColor", this->sprite->GetTint());

        glActiveTexture(GL_TEXTURE0);
        texture->Bind();

        glBindVertexArray(this->vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    } else {
        this->InitTexture();
    }
}

void SpriteRenderer::InitRenderData()
{
    this->vao = ResourceManager::GetVertexArrayObject("builtin_sprite");

    if (this->vao == 0) {
        // clang-format off
        float vertices[] = {
            // Position  // UV
            0.0f, 0.0f,  0.0f, 0.0f,
            0.0f, 1.0f,  0.0f, 1.0f,
            1.0f, 0.0f,  1.0f, 0.0f,
            1.0f, 1.0f,  1.0f, 1.0f
        };
        // clang-format on

        unsigned int indices[] = {
            1, 0, 2,
            1, 2, 3
        };

        unsigned int vbo, ebo;

        glGenVertexArrays(1, &this->vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(this->vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        ResourceManager::SaveVertexArrayOject("builtin_sprite", this->vao);
    }
}

void SpriteRenderer::InitShader()
{
    this->shader = ResourceManager::GetShader("builtin_sprite");

    if (!shader) {
        std::string vertexSource = R"(
            #version 330 core

            layout (location = 0) in vec2 aPos;
            layout (location = 1) in vec2 aUV;

            out vec2 _texCoords;

            uniform mat4 model;
            uniform mat4 projection;

            void main()
            {
                _texCoords = aUV;
                gl_Position = projection * model * vec4(aPos, 0.0, 1.0);
            }
        )";

        std::string fragmentSource = R"(
            #version 330 core

            in vec2 _texCoords;

            out vec4 color;

            uniform sampler2D sprite;
            uniform vec3 tintColor;

            void main()
            {
                color = vec4(tintColor, 1.0) * texture(sprite, _texCoords);
            }
        )";

        this->shader = ResourceManager::LoadShaderSource("builtin_sprite", vertexSource, fragmentSource);
        this->shader->Use();
        this->shader->SetInteger("sprite", 0);
    }
}

void SpriteRenderer::InitTexture()
{
    EntityPtr ent = this->entity.lock();

    if (ent && this->sprite) {
        Texture2DPtr texture = this->sprite->GetTexture();
        ent->SetBaseScale(texture->GetWidth(), texture->GetHeight());
        texture->SetFilterMin(GL_NEAREST_MIPMAP_LINEAR);
        texture->SetFilterMag(GL_NEAREST_MIPMAP_LINEAR);

        this->initialized = true;
    }
}