#ifndef TOMENGINE_SHADER_HPP
#define TOMENGINE_SHADER_HPP

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace tomengine
{
class Shader
{
public:
    GLuint ID;

    Shader() {}

    Shader& Use();
    void Compile(const std::string& pVertSource, const std::string& pFragSource, const std::string& pGeomSource = "");
    void Compile(const GLchar* pVertSource, const GLchar* pFragSource, const GLchar* pGeomSource = nullptr);

    void SetFloat(const std::string& pName, GLfloat pValue, GLboolean pUseShader = false);
    void SetInteger(const std::string& pName, GLint pValue, GLboolean pUseShader = false);
    void SetVector2f(const std::string& pName, const glm::vec2& pValue, GLboolean pUseShader = false);
    void SetVector3f(const std::string& pName, const glm::vec3& pValue, GLboolean pUseShader = false);
    void SetVector4f(const std::string& pName, const glm::vec4& pValue, GLboolean pUseShader = false);
    void SetMatrix4f(const std::string& pName, const glm::mat4& pValue, GLboolean pUseShader = false);

private:
    void CheckCompilerErrors(GLuint pObject);
    void CheckLinkerErrors(GLuint pObject);
};
} // namespace tomengine

#endif
