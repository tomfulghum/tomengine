#ifndef TOMENGINE_COMMON_HPP
#define TOMENGINE_COMMON_HPP

#include <memory>

namespace tomengine
{

// Main ------------------------------------
class Application;
typedef std::shared_ptr<Application> ApplicationPtr;
typedef std::weak_ptr<Application> ApplicationWPtr;

class Entity;
typedef std::shared_ptr<Entity> EntityPtr;
typedef std::weak_ptr<Entity> EntityWPtr;

class Shader;
typedef std::shared_ptr<Shader> ShaderPtr;
typedef std::weak_ptr<Shader> ShaderWPtr;

class Sprite;
typedef std::shared_ptr<Sprite> SpritePtr;
typedef std::weak_ptr<Sprite> SpriteWPtr;

class Texture2D;
typedef std::shared_ptr<Texture2D> Texture2DPtr;
typedef std::weak_ptr<Texture2D> Texture2DWPtr;

// Component -------------------------------
class Component;
typedef std::shared_ptr<Component> ComponentPtr;
typedef std::unique_ptr<Component> ComponentUPtr;
typedef std::weak_ptr<Component> ComponentWPtr;

} // namespace tomengine

#endif