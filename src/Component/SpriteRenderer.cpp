#include "Component/SpriteRenderer.hpp"

#include <iostream>
#include <string>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

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
    InitRenderData();
    InitShader();
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

void SpriteRenderer::Render()
{
    if (this->sprite)
    {
        this->shader->Use();
        this->shader->SetMatrix4f("model", this->entity->GetTransformMatrix());
        this->shader->SetMatrix4f("projection", Environment::OrthoProjectionMatrix());
        this->shader->SetVector3f("tintColor", this->sprite->GetTint());

        glActiveTexture(GL_TEXTURE0);
        this->sprite->GetTexture()->Bind();

        glBindVertexArray(this->vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
}

void SpriteRenderer::InitRenderData()
{
    this->vao = ResourceManager::GetVertexArrayObject("builtin_sprite");

    if (this->vao == 0)
    {
        std::cout << "Beep!" << std::endl;
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

        std::cout << this->vao << " " << vbo << " " << ebo << std::endl;

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

    if (!shader)
    {
        std::cout << "Boop!" << std::endl;

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