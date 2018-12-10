#ifndef TOMENGINE_RESOURCE_MANAGER_HPP
#define TOMENGINE_RESOURCE_MANAGER_HPP

#include <map>
#include <memory>
#include <string>

#include "Common.hpp"

namespace tomengine
{

class ResourceManager
{
public:
    static std::map<std::string, ShaderPtr> Shaders;
    static std::map<std::string, Texture2DPtr> Textures;
    static std::map<std::string, unsigned int> VertexArrayObjects;

    static ShaderPtr LoadShaderFiles(const std::string& name, const std::string& vertShaderFile, const std::string& fragShaderFile, const std::string& geomShaderFile = "");
    static ShaderPtr LoadShaderSource(const std::string& name, const std::string& vertShaderSrc, const std::string& fragShaderSrc, const std::string& geomShaderSrc = "");
    static ShaderPtr GetShader(const std::string& name);
    static Texture2DPtr LoadTexture2D(const std::string& file, const std::string& name);
    static Texture2DPtr GetTexture2D(const std::string& name);
    static int SaveVertexArrayOject(const std::string& name, const int vao);
    static int GetVertexArrayObject(const std::string& name);

    static void Clear();

private:
    ResourceManager() {}
    static Texture2DPtr LoadTexture2DFromFile(const std::string& file);
    static std::string LoadTextFile(const std::string& file);
};

} // namespace tomengine

#endif