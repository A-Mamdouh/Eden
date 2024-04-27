#include <Eden/Scene/SceneSystem.hpp>

namespace Eden
{
    Entity *SceneSystem::CreateObject(Entity *parent, Transform localTransform)
    {
        // Create new entity
        entities.push_back(std::make_unique<Entity>());
        auto newEntity = entities[entities.size() - 1].get();
        // Create scene graph node and populate its members
        nodes.push_back(std::make_unique<SceneNodeComponent>(newEntity));
        auto newNode = nodes[nodes.size() - 1].get();
        newNode->transform = localTransform;
        if (parent != nullptr)
        {
            auto parentNode = parent->GetComponent<SceneNodeComponent>();
            newNode->parent = parentNode;
        }
        // Register new component to the entity
        newEntity->AddComponent(newNode);
        // Return new entity
        return newEntity;
    }

    Entity *SceneSystem::CreateObject(Entity *parent)
    {
        return CreateObject(parent, Transform());
    }

    Entity *SceneSystem::CreateObject(Transform transform)
    {
        return CreateObject(nullptr, transform);
    }

    Entity *SceneSystem::CreateObject()
    {
        return CreateObject(nullptr, Transform());
    }
}
