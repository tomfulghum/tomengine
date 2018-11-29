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

    int GetWidth() const { return this->width; }
    int GetHeight() const { return this->height; }
    GLuint GetInternalFormat() const { return this->internalFormat; };
    GLuint GetImageFormat() const { return this->imageFormat; };
    GLuint GetWrappingModeS() const { return this->wrappingModeS; };
    GLuint GetWrappingModeT() const { return this->wrappingModeT; };
    GLuint GetFilterMin() const { return this->filterMin; };
    GLuint GetFilterMag() const { return this->filterMag; };

    void SetInternalFormat(const unsigned int format);
    void SetImageFormat(const unsigned int format);

    void Generate(const unsigned int width, const unsigned int height, const unsigned char* data);
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