#include "Texture2D.hpp"

using namespace tomengine;

Texture2D::Texture2D() :
    width(0),
    height(0),
    internalFormat(GL_RGB),
    wrappingModeS(GL_REPEAT),
    wrappingModeT(GL_REPEAT),
    filterMin(GL_LINEAR),
    filterMag(GL_LINEAR)
{
    glGenTextures(1, &this->ID);
};

void Texture2D::SetInternalFormat(GLuint pFormat)
{
    this->internalFormat = pFormat;
}

void Texture2D::SetImageFormat(GLuint pFormat)
{
    this->imageFormat = pFormat;
}

void Texture2D::Generate(const unsigned int pWidth, const unsigned int pHeight, const unsigned char* pData)
{
    this->width = pWidth;
    this->height = pHeight;

    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, this->internalFormat, this->width, this->height, 0, this->imageFormat, GL_UNSIGNED_BYTE, pData);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrappingModeS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrappingModeT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filterMag);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->ID);
}