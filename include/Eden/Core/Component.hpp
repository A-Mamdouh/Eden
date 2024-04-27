#pragma once
#include <Eden/Core/Core.hpp>

namespace Eden
{
    // Forwards declaration
    class Entity;

    /// @brief Base component class where all components extend this one. Components act as attributes that can be added to an entity which owns the component
    class Component : public EdenResource
    {
    public:
        Component(Entity *owner);
        Unique(Component);
        virtual ~Component() = default;

    protected:
        Entity *owner;
    };
};
