#include <Eden/Scene/SceneComponents.hpp>

namespace Eden
{
    Transform SceneNodeComponent::GetLocalTransform() const
    {
        return transform;
    }

    glm::mat4 SceneNodeComponent::GetModelTransform() const
    {
        if (parent.has_value())
        {
            return parent.value()->GetModelTransform() * transform.GetMat();
        }
        return transform.GetMat();
    }

    SceneNodeComponent::SceneNodeComponent(Entity *owner) : Component(owner) {}

    void SceneNodeComponent::SetLocalTransform(const Transform newTransform)
    {
        transform = newTransform;
    }

    std::optional<Entity *> Eden::SceneNodeComponent::GetParent()
    {
        if(parent.has_value())
        {
            return parent.value()->owner;
        }
        return {};
    }
}
