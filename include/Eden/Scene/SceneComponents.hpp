#pragma once

#include <Eden/Core/Core.hpp>
#include <Eden/Core/Component.hpp>
#include <Eden/Core/Transform.hpp>

namespace Eden
{
    // Forward declaration
    class SceneSystem;

    class SceneNodeComponent : public Component
    {
    public:
        Transform GetLocalTransform() const;
        glm::mat4 GetModelTransform() const;
        SceneNodeComponent(Entity *owner);
        virtual ~SceneNodeComponent() = default;

        /// @brief Set the local transform of a node
        /// @param newTransform new value of the transform
        void SetLocalTransform(const Transform newTransform);

        /// @brief Get the parent entity if exists
        /// @return parent entity if entity is nested, otherwise nullopt
        std::optional<Entity*> GetParent();

    private:
        std::optional<SceneNodeComponent *> parent = std::nullopt;
        Transform transform = Transform{};
        friend SceneSystem;
    };
}