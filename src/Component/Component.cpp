#include "Component/Component.hpp"

using namespace tomengine;

const std::size_t Component::Type = std::hash<std::string>()(TO_STRING(Component));