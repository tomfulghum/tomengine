#include "Shader.hpp"

#include <iostream>

#include <glm/gtc/type_ptr.hpp>

using namespace tomengine;

Shader& Shader::Use()
{
    glUseProgram(this->ID);
    return *this;
}

void Shader::Compile(const std::string& pVertSource, const std::string& pFragSource, const std::string& pGeomSource)
{
    const GLchar* vertexShaderSource = pVertSource.c_str();
    const GLchar* fragmentShaderSource = pFragSource.c_str();
    const GLchar* geometryShaderSource = pGeomSource.empty() ? nullptr : pGeomSource.c_str();

    Compile(vertexShaderSource, fragmentShaderSource, geometryShaderSource);
}

void Shader::Compile(const GLchar* pVertSource, const GLchar* pFragSource, const GLchar* pGeomSource)
{
    GLuint vertexShader, fragmentShader, geometryShader;

    // Vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &pVertSource, NULL);
    glCompileShader(vertexShader);
    CheckCompilerErrors(vertexShader);

    // Fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &pFragSource, NULL);
    glCompileShader(fragmentShader);
    CheckCompilerErrors(fragmentShader);

    // Geometry shader
    if (pGeomSource != nullptr)
    {
        geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometryShader, 1, &pGeomSource, NULL);
        glCompileShader(geometryShader);
        CheckCompilerErrors(geometryShader);
    }

    // Create shader program and link shaders
    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertexShader);
    glAttachShader(this->ID, fragmentShader);
    if (pGeomSource != nullptr)
    {
        glAttachShader(this->ID, geometryShader);
    }
    glLinkProgram(this->ID);
    CheckLinkerErrors(this->ID);

    // Clean up
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    if (pGeomSource != nullptr)
    {
        glDeleteShader(geometryShader);
    }
}

void Shader::SetFloat(const std::string& pName, GLfloat pValue, GLboolean pUseShader)
{
    if (pUseShader)
    {
        this->Use();
    }
    glUniform1f(glGetUniformLocation(this->ID, pName.c_str()), pValue);
}

void Shader::SetInteger(const std::string& pName, GLint pValue, GLboolean pUseShader)
{
    if (pUseShader)
    {
        this->Use();
    }
    glUniform1i(glGetUniformLocation(this->ID, pName.c_str()), pValue);
}

void Shader::SetVector2f(const std::string& pName, const glm::vec2& pValue, GLboolean pUseShader)
{
    if (pUseShader)
    {
        this->Use();
    }
    glUniform2f(glGetUniformLocation(this->ID, pName.c_str()), pValue.x, pValue.y);
}

void Shader::SetVector3f(const std::string& pName, const glm::vec3& pValue, GLboolean pUseShader)
{
    if (pUseShader)
    {
        this->Use();
    }
    glUniform3f(glGetUniformLocation(this->ID, pName.c_str()), pValue.x, pValue.y, pValue.z);
}

void Shader::SetVector4f(const std::string& pName, const glm::vec4& pValue, GLboolean pUseShader)
{
    if (pUseShader)
    {
        this->Use();
    }
    glUniform4f(glGetUniformLocation(this->ID, pName.c_str()), pValue.x, pValue.y, pValue.z, pValue.w);
}

void Shader::SetMatrix4f(const std::string& pName, const glm::mat4& pValue, GLboolean pUseShader)
{
    if (pUseShader)
    {
        this->Use();
    }
    glUniformMatrix4fv(glGetUniformLocation(this->ID, pName.c_str()), 1, GL_FALSE, glm::value_ptr(pValue));
}

void Shader::CheckCompilerErrors(GLuint pObject)
{
    GLint success;
    GLchar infoLog[1024];

    glGetShaderiv(pObject, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(pObject, 1024, NULL, infoLog);
        std::cout << "ERROR::Shader: Failed to compile shader (ID: " << this->ID << ")\n"
                  << infoLog << std::endl;
    }
}

void Shader::CheckLinkerErrors(GLuint pObject)
{
    GLint success;
    GLchar infoLog[1024];

    glGetProgramiv(pObject, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(pObject, 1024, NULL, infoLog);
        std::cout << "ERROR::Shader: Failed to link shader (ID: " << this->ID << ")\n"
                  << infoLog << std::endl;
    }
}