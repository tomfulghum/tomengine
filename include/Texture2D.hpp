#ifndef TOMENGINE_TEXTURE2D_HPP
#define TOMENGINE_TEXTURE2D_HPP

#include <memory>

#include <glad/glad.h>

namespace tomengine
{

class Texture2D;
typedef std::shared_ptr<Texture2D> Texture2DPtr;
typedef std::weak_ptr<Texture2D> Texture2DPtrW;

class Texture2D
{
public:
    GLuint ID;

    Texture2D();

    int GetWidth() { return this->width; }
    int GetHeight() { return this->height; }
    GLuint GetInternalFormat() { return this->internalFormat; };
    GLuint GetImageFormat() { return this->imageFormat; };
    GLuint GetWrappingModeS() { return this->wrappingModeS; };
    GLuint GetWrappingModeT() { return this->wrappingModeT; };
    GLuint GetFilterMin() { return this->filterMin; };
    GLuint GetFilterMag() { return this->filterMag; };

    void SetInternalFormat(GLuint pFormat);
    void SetImageFormat(GLuint pFormat);

    void Generate(GLuint pWidth, GLuint pHeight, unsigned char* pData);
    void Bind() const;

private:
    GLuint width, height;
    GLuint internalFormat;
    GLuint imageFormat;
    GLuint wrappingModeS;
    GLuint wrappingModeT;
    GLuint filterMin;
    GLuint filterMag;
};

} // namespace tomengine

#endif