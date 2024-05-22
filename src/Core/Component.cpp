#include <Eden/Core/Component.hpp>
#include <Eden/Core/Entity.hpp>

namespace Eden
{
    Component::Component(Entity *ownerParam) : owner{ownerParam} {}
}
