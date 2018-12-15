#include "Component/Component.hpp"

using namespace tomengine;

const std::size_t Component::Type = std::hash<std::string>()(TO_STRING(Component));

Component::Component() :
    active(true), initialized(false)
{
}

void Component::Init()
{
    if (!this->initialized) {
        this->Start();
        this->initialized = true;
    }
}

void Component::SetActive(bool pActive)
{
    this->active = pActive;
    if (active) {
        this->Init();
    }
}