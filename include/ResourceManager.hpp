#ifndef TOMENGINE_RESOURCE_MANAGER_HPP
#define TOMENGINE_RESOURCE_MANAGER_HPP

#include <map>
#include <string>

#include "Shader.hpp"
#include "Texture2D.hpp"

namespace tomengine
{
class ResourceManager
{
public:
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture2D> Textures;

    static Shader LoadShader(const std::string& pVertShaderFile, const std::string& pFragShaderFile, const std::string& pGeomShaderFile, const std::string& pName);
    static Shader& GetShader(const std::string& pName);
    static Texture2D LoadTexture2D(const std::string& pFile, const std::string& pName);
    static Texture2D& GetTexture2D(const std::string& pName);

    static void Clear();

private:
    ResourceManager() {}
    static Shader LoadShaderFromFile(const std::string& pVertShaderFile, const std::string& pFragShaderFile, const std::string& pGeomShaderFile = "");
    static Texture2D LoadTexture2DFromFile(const std::string& pFile);
    static std::string LoadTextFile(const std::string& pFile);
};
} // namespace tomengine

#endif