#include "ResourceManager.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace tomengine;

std::map<std::string, ShaderPtr> ResourceManager::Shaders;
std::map<std::string, Texture2DPtr> ResourceManager::Textures;

ShaderPtr ResourceManager::LoadShaderFiles(const std::string& pName, const std::string& pVertShaderFile, const std::string& pFragShaderFile, const std::string& pGeomShaderFile)
{
    std::string vertexSrc = LoadTextFile(pVertShaderFile);
    std::string fragmentSrc = LoadTextFile(pFragShaderFile);
    std::string geometrySrc = pGeomShaderFile.empty() ? "" : LoadTextFile(pGeomShaderFile);

    return LoadShaderSource(pName, pVertShaderFile, pFragShaderFile, pGeomShaderFile);
}

ShaderPtr ResourceManager::LoadShaderSource(const std::string& pName, const std::string& pVertShaderSrc, const std::string& pFragShaderSrc, const std::string& pGeomShaderSrc)
{
    const GLchar* vertexSrc = pVertShaderSrc.c_str();
    const GLchar* fragmentSrc = pFragShaderSrc.c_str();
    const GLchar* geometrySrc = pGeomShaderSrc.empty() ? nullptr : pGeomShaderSrc.c_str();

    ShaderPtr shader = std::make_shared<Shader>();
    shader->Compile(vertexSrc, fragmentSrc, geometrySrc);

    Shaders[pName] = shader;
    return Shaders[pName];
}

ShaderPtr ResourceManager::GetShader(const std::string& pName)
{
    return Shaders[pName];
}

Texture2DPtr ResourceManager::LoadTexture2D(const std::string& pFile, const std::string& pName)
{
    Textures[pName] = LoadTexture2DFromFile(pFile);
    return Textures[pName];
}

Texture2DPtr ResourceManager::GetTexture2D(const std::string& pName)
{
    return Textures[pName];
}

void ResourceManager::Clear()
{
    for (auto iShader : Shaders)
    {
        glDeleteProgram(iShader.second->ID);
    }
    for (auto iTexture2D : Textures)
    {
        glDeleteTextures(1, &iTexture2D.second->ID);
    }

    Shaders.clear();
    Textures.clear();
}

Texture2DPtr ResourceManager::LoadTexture2DFromFile(const std::string& pFile)
{
    int width, height, channels;
    //stbi_set_flip_vertically_on_load(true);
    unsigned char* imageData = stbi_load(pFile.c_str(), &width, &height, &channels, 0);

    Texture2DPtr texture = std::make_shared<Texture2D>();

    if (imageData)
    {
        if (channels == 4)
        {
            texture->SetInternalFormat(GL_RGBA);
            texture->SetImageFormat(GL_RGBA);
        }

        texture->Generate(width, height, imageData);
    }
    else
    {
        std::cout << "ERROR::ResourceManager: Failed to load image file: " << pFile << std::endl;
    }

    stbi_image_free(imageData);
    return texture;
}

std::string ResourceManager::LoadTextFile(const std::string& pFile)
{
    std::string content;

    try
    {
        std::ifstream file(pFile);
        std::stringstream fileStream;

        fileStream << file.rdbuf();
        file.close();

        content = fileStream.str();
    }
    catch (std::exception e)
    {
        std::cout << "ERROR::ResourceManager: Failed to load text file: " << pFile << std::endl;
    }

    return content;
}