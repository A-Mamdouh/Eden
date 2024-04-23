#include <Eden/Core/Entity.hpp>

/// @brief Create ID @warning not thread safe
/// @return a new ID
uint32_t CreateID()
{
    static uint32_t id = 0;
    return id++;
}

namespace Eden
{
    const uint32_t Entity::GetId() const
    {
        return id;
    }

    Entity::Entity() : id{CreateID()} {}

    void Entity::AddComponent(std::shared_ptr<Component> component)
    {
        // Early return if component already exists
        if (std::find_if(components.begin(), components.end(), [&component](auto &other)
                         { return component.get() == other.get(); }) != components.end())
        {
            return;
        }
        components.push_back(component);
    }
}