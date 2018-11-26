#ifndef TOMENGINE_RESOURCE_MANAGER_HPP
#define TOMENGINE_RESOURCE_MANAGER_HPP

#include <map>
#include <memory>
#include <string>

#include "Shader.hpp"
#include "Texture2D.hpp"

namespace tomengine
{

class ResourceManager;
typedef std::shared_ptr<ResourceManager> ResourceManagerPtr;
typedef std::weak_ptr<ResourceManager> ResourceManagerPtrW;

class ResourceManager
{
public:
    static std::map<std::string, ShaderPtr> Shaders;
    static std::map<std::string, Texture2DPtr> Textures;

    static ShaderPtr LoadShader(const std::string& pVertShaderFile, const std::string& pFragShaderFile, const std::string& pGeomShaderFile, const std::string& pName);
    static ShaderPtr GetShader(const std::string& pName);
    static Texture2DPtr LoadTexture2D(const std::string& pFile, const std::string& pName);
    static Texture2DPtr GetTexture2D(const std::string& pName);

    static void Clear();

private:
    ResourceManager() {}
    static ShaderPtr LoadShaderFromFile(const std::string& pVertShaderFile, const std::string& pFragShaderFile, const std::string& pGeomShaderFile = "");
    static Texture2DPtr LoadTexture2DFromFile(const std::string& pFile);
    static std::string LoadTextFile(const std::string& pFile);
};

} // namespace tomengine

#endif