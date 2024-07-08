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
            auto lockedParent = parent->lock();
            if (lockedParent != nullptr)
            {
                return lockedParent->GetModelTransform() * transform.GetMat();
            }
        }
        return transform.GetMat();
    }

    SceneNodeComponent::SceneNodeComponent(std::optional<std::weak_ptr<Entity>> owner) : Component(owner) {}

    void SceneNodeComponent::SetLocalTransform(const Transform newTransform)
    {
        transform = newTransform;
    }

    std::optional<std::weak_ptr<Entity>> Eden::SceneNodeComponent::GetParent()
    {
        if(parent.has_value())
        {
            auto lockedParent = parent->lock();
            if (lockedParent != nullptr)
            {
                return lockedParent->owner;
            }
        }
        return {};
    }
}
