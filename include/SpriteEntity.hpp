#ifndef TOMENGINE_SPRITE_ENTITY_HPP
#define TOMENGINE_SPRITE_ENTITY_HPP

#include <memory>

#include "Common.hpp"
#include "Entity.hpp"
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
    SpriteEntity(SpritePtr sprite);
    SpriteEntity(Texture2DPtr texture);

    SpritePtr GetSprite() const { return this->sprite; }

private:
    SpritePtr sprite;
    ShaderPtr shader;

    void InitializeTransform();
};

} // namespace tomengine

#endif