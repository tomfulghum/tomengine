#include <string>

#include "ResourceManager.hpp"
#include "SpriteRenderer.hpp"

using namespace tomengine;

SpriteRenderer::SpriteRenderer()
{
    InitRenderData();
    InitShader();
}

SpriteRenderer::~SpriteRenderer()
{
    glDeleteVertexArrays(1, &vao);
}

void SpriteRenderer::DrawSprite(SpriteEntityPtr pEntity)
{
    SpritePtr sprite = pEntity->GetSprite();

    this->shader->Use();
    this->shader->SetMatrix4f("model", pEntity->GetTransformMatrix());
    this->shader->SetVector3f("tintColor", sprite->GetTint());

    glActiveTexture(GL_TEXTURE0);
    sprite->GetTexture()->Bind();

    glBindVertexArray(this->vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::InitRenderData()
{
    GLuint vbo;
    GLfloat vertices[] = {
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &(this->vao));
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->vao);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SpriteRenderer::InitShader()
{
    std::string vertexSource = R"(
        #version 400 core

        layout (location = 0) in vec4 vertex;

        out vec2 _texCoords;

        uniform mat4 model;
        uniform mat4 projection;

        void main()
        {
            texCoords = vertex.zw;
            gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
        }
    )";

    std::string fragmentSource = R"(
        #versin 400 core

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
}