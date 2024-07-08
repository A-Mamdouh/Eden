#pragma once

#include <Eden/Core/Core.hpp>
#include <Eden/Core/Entity.hpp>
#include <Eden/Core/Transform.hpp>
#include <Eden/Scene/SceneComponents.hpp>

namespace Eden
{
    class SceneSystem
    {
    public:
        /// @brief Create a new object and register into scene graph
        /// @param parent parent object to nest the object under
        /// @param localTransform Local transform from parent from parent
        /// @return pointer to newly created entity
        std::shared_ptr<Entity> CreateObject(std::optional<std::weak_ptr<Entity>> parent, Transform localTransform);

        /// @copybrief Entity::CreateObject
        /// @param parent optional parent object to nest the object under
        /// @return pointer to newly created entity
        std::shared_ptr<Entity> CreateObject(std::optional<std::weak_ptr<Entity>> parent);

        /// @copybrief Entity::CreateObject
        /// @param transform set local transform of the new object. Will be the world/model transform since the object is not nested
        /// @return pointer to newly created entity
        std::shared_ptr<Entity> CreateObject(Transform transform);

        /// @copybrief Entity::CreateObject
        /// @return pointer to newly created entity
        std::shared_ptr<Entity> CreateObject();

    private:
        std::vector<std::shared_ptr<Entity>> entities;
        std::vector<std::shared_ptr<SceneNodeComponent>> nodes;
    };
}