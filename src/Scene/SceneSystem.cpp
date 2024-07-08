#include <Eden/Scene/SceneSystem.hpp>

namespace Eden
{
    std::shared_ptr<Entity> SceneSystem::CreateObject(std::optional<std::weak_ptr<Entity>> parent, Transform localTransform)
    {
        // Create new entity
        // entities.push_back(Entity::New());
        entities.push_back(std::make_shared<Entity>());
        auto newEntity = entities.back();
        // Create scene graph node and populate its members
        // nodes.push_back(SceneNodeComponent::New(newEntity));
        nodes.push_back(std::make_shared<SceneNodeComponent>(newEntity));
        auto newNode = nodes.back();
        newNode->transform = localTransform;
        if (parent.has_value())
        {
            std::shared_ptr<Entity> lockedParent;
            if (lockedParent = parent->lock())
            {
                auto parentNode = lockedParent->GetComponent<SceneNodeComponent>();
                newNode->parent = parentNode;
            }
        }
        // Register new component to the entity
        newEntity->AddComponent(newNode);
        // Return new entity
        return newEntity;
    }

    std::shared_ptr<Entity> SceneSystem::CreateObject(std::optional<std::weak_ptr<Entity>> parent)
    {
        return CreateObject(parent, Transform());
    }

    std::shared_ptr<Entity> SceneSystem::CreateObject(Transform transform)
    {
        return CreateObject({}, transform);
    }

    std::shared_ptr<Entity> SceneSystem::CreateObject()
    {
        return CreateObject({}, Transform());
    }
}
