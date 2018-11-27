#ifndef TOMENGINE_SPRITE_ENTITY_HPP
#define TOMENGINE_SPRITE_ENTITY_HPP

#include <memory>

#include "Entity/Entity.hpp"
#include "Sprite.hpp"
#include "Texture2D.hpp"

namespace tomengine
{

class SpriteEntity;
typedef std::shared_ptr<SpriteEntity> SpriteEntityPtr;
typedef std::weak_ptr<SpriteEntity> SpriteEntityPtrW;

class SpriteEntity : public Entity
{
public:
    SpriteEntity(SpritePtr pSprite);
    SpriteEntity(Texture2DPtr pTexture);

    SpritePtr GetSprite() { return this->sprite; }

private:
    SpritePtr sprite;
    ShaderPtr shader;

    void InitializeTransform();
};

} // namespace tomengine

#endif