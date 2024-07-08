#pragma once
#include <Eden/Core/Core.hpp>

namespace Eden
{
    // Forwards declaration
    class Entity;

    /// @brief Base component class where all components extend this one. Components act as attributes that can be added to an entity which owns the component
    class Component : public EdenResource<Component>
    {
    public:
        Component(std::optional<std::weak_ptr<Entity>> owner);
        UniqueResource(Component);
        virtual ~Component() = default;

    protected:
        std::optional<std::weak_ptr<Entity>> owner;
    };
};
