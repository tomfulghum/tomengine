#include "ResourceManager.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace tomengine;

std::map<std::string, Shader> ResourceManager::Shaders;
std::map<std::string, Texture2D> ResourceManager::Textures;

Shader ResourceManager::LoadShader(const std::string& pVertShaderFile, const std::string& pFragShaderFile, const std::string& pGeomShaderFile, const std::string& pName)
{
    Shaders[pName] = LoadShaderFromFile(pVertShaderFile, pFragShaderFile, pGeomShaderFile);
    return Shaders[pName];
}

Shader& ResourceManager::GetShader(const std::string& pName)
{
    return Shaders[pName];
}

Texture2D ResourceManager::LoadTexture2D(const std::string& pFile, const std::string& pName)
{
    Textures[pName] = LoadTexture2DFromFile(pFile);
    return Textures[pName];
}

Texture2D& ResourceManager::GetTexture2D(const std::string& pName)
{
    return Textures[pName];
}

void ResourceManager::Clear()
{
    for (auto iShader : Shaders)
    {
        glDeleteProgram(iShader.second.ID);
    }
    for (auto iTexture2D : Textures)
    {
        glDeleteTextures(1, &iTexture2D.second.ID);
    }

    Shaders.clear();
    Textures.clear();
}

Shader ResourceManager::LoadShaderFromFile(const std::string& pVertShaderFile, const std::string& pFragShaderFile, const std::string& pGeomShaderFile)
{
    std::string vertexSourceTemp = LoadTextFile(pVertShaderFile);
    std::string fragmentSourceTemp = LoadTextFile(pFragShaderFile);
    std::string geometrySourceTemp = pGeomShaderFile.empty() ? "" : LoadTextFile(pGeomShaderFile);
    const GLchar* vertexSource = vertexSourceTemp.c_str();
    const GLchar* fragmentSource = fragmentSourceTemp.c_str();
    const GLchar* geometrySource = geometrySourceTemp.empty() ? nullptr : geometrySourceTemp.c_str();

    Shader shader;
    shader.Compile(vertexSource, fragmentSource, geometrySource);
    return shader;
}

Texture2D ResourceManager::LoadTexture2DFromFile(const std::string& pFile)
{
    int width, height, channels;
    unsigned char* imageData = stbi_load(pFile.c_str(), &width, &height, &channels, 0);

    Texture2D texture;

    if (imageData)
    {
        if (channels == 4)
        {
            texture.SetInternalFormat(GL_RGBA);
            texture.SetImageFormat(GL_RGBA);
        }

        texture.Generate(width, height, imageData);
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