#ifndef TOMENGINE_RESOURCE_MANAGER_HPP
#define TOMENGINE_RESOURCE_MANAGER_HPP

#include <map>
#include <memory>
#include <string>

#include "Shader.hpp"
#include "Texture2D.hpp"

namespace tomengine
{

class ResourceManager
{
public:
    static std::map<std::string, ShaderPtr> Shaders;
    static std::map<std::string, Texture2DPtr> Textures;

    static ShaderPtr LoadShaderFiles(const std::string& pName, const std::string& pVertShaderFile, const std::string& pFragShaderFile, const std::string& pGeomShaderFile = "");
    static ShaderPtr LoadShaderSource(const std::string& pName, const std::string& pVertShaderSrc, const std::string& pFragShaderSrc, const std::string& pGeomShaderSrc = "");
    static ShaderPtr GetShader(const std::string& pName);
    static Texture2DPtr LoadTexture2D(const std::string& pFile, const std::string& pName);
    static Texture2DPtr GetTexture2D(const std::string& pName);

    static void Clear();

private:
    ResourceManager() {}
    static Texture2DPtr LoadTexture2DFromFile(const std::string& pFile);
    static std::string LoadTextFile(const std::string& pFile);
};

} // namespace tomengine

#endif