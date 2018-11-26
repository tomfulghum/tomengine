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
    SpriteEntity(SpritePtr pSprite, ShaderPtr pShader = nullptr);
    SpriteEntity(Texture2DPtr pTexture, ShaderPtr pShader = nullptr);

    SpritePtr GetSprite() { return this->sprite; }

private:
    SpritePtr sprite;
    ShaderPtr shader;

    void InitializeTransform();
};

} // namespace tomengine