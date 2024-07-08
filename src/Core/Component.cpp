#include <Eden/Core/Component.hpp>
#include <Eden/Core/Entity.hpp>

namespace Eden
{
    Component::Component(std::optional<std::weak_ptr<Entity>> ownerParam) : owner{ownerParam} {}
}
