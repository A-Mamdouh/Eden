#include <Eden/Core/Entity.hpp>
#include <Eden/Scene/SceneComponents.hpp>

namespace Eden
{

    void Entity::AddComponent(std::shared_ptr<Component> component)
    {
        // Early return if component already exists
        if (std::find_if(components.begin(), components.end(), [&component](auto other)
                         { return component == other; }) != components.end())
        {
            return;
        }
        components.push_back(component);
    }

    Transform Entity::GetLocalTransform() const
    {
        auto nodeComponent = GetComponent<SceneNodeComponent>();
        if (!nodeComponent.has_value())
        {
            throw std::runtime_error("Entity is not assigned a scene node");
        }
        return nodeComponent.value()->GetLocalTransform();
    }

    glm::mat4 Entity::GetModelTransform() const
    {
        auto nodeComponent = GetComponent<SceneNodeComponent>();
        if (!nodeComponent.has_value())
        {
            throw std::runtime_error("Entity is not assigned a scene node");
        }
        return nodeComponent.value()->GetModelTransform();
    }

}