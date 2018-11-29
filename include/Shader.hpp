#ifndef TOMENGINE_SHADER_HPP
#define TOMENGINE_SHADER_HPP

#include <memory>
#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace tomengine
{

class Shader;
typedef std::shared_ptr<Shader> ShaderPtr;
typedef std::weak_ptr<Shader> ShaderPtrW;

class Shader
{
public:
    GLuint ID;

    Shader() {}

    void Use();
    void Compile(const std::string& vertSource, const std::string& fragSource, const std::string& geomSource = "");
    void Compile(const GLchar* vertSource, const GLchar* fragSource, const GLchar* geomSource = nullptr);

    void SetFloat(const std::string& name, GLfloat value, GLboolean useShader = false);
    void SetInteger(const std::string& name, GLint value, GLboolean useShader = false);
    void SetVector2f(const std::string& name, const glm::vec2& value, GLboolean useShader = false);
    void SetVector3f(const std::string& name, const glm::vec3& value, GLboolean useShader = false);
    void SetVector4f(const std::string& name, const glm::vec4& value, GLboolean useShader = false);
    void SetMatrix4f(const std::string& name, const glm::mat4& value, GLboolean useShader = false);

private:
    void CheckCompilerErrors(GLuint object);
    void CheckLinkerErrors(GLuint object);
};

} // namespace tomengine

#endif
