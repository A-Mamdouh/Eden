#pragma once

#include <Eden/Core/Core.hpp>
#include <Eden/Core/Component.hpp>
#include <Eden/Core/Transform.hpp>

namespace Eden
{

    class Entity : public EdenResource
    {
        Unique(Entity);

    public:
        /// @brief Get the first instance of a component of a certain type
        /// @tparam ComponentType Type of component to look for
        /// @return returns the first component if any is found. Otherwise, returns std::nullopt
        template <class ComponentType>
        // Asserting that ComponentType is an instance of Eden::Component
            requires std::is_base_of<Component, ComponentType>::value
        const std::optional<ComponentType *> GetComponent()
        {
            for(const auto component : components)
                if(IsInstance<const ComponentType>(component))
                    return static_cast<ComponentType*>(component);
            return std::nullopt;
        }

        /// @copydoc Eden::Entity::GetComponent
        template <class ComponentType>
        // Asserting that ComponentType is an instance of Eden::Component
            requires std::is_base_of<Component, ComponentType>::value
        const std::optional<ComponentType *> GetComponent() const
        {
            for (auto component : components)
                if (IsInstance<ComponentType>(component))
                    return static_cast<ComponentType *>(component);
            return std::nullopt;
        }

        /// @brief Get all components of a given type
        /// @tparam ComponentType Type of components to look for
        /// @return returns a vector of matching components
        template <class ComponentType>
        // Asserting that ComponentType is an instance of Eden::Component
            requires std::is_base_of<Component, ComponentType>::value
        std::vector<ComponentType *> GetComponents()
        {
            auto result = components | std::ranges::views::filter([](auto component)
                                                                  { return IsInstance<ComponentType>(component); }) |
                          std::ranges::views::transform([](auto component)
                                                        { return static_cast<ComponentType *>(component); });
            return std::vector<ComponentType *>(result.begin(), result.end());
        }

        /// @brief the local transform describes the positional information relative to the object's parent in the scene
        /// @return the transform for the current object relative to its parent
        Transform GetLocalTransform() const;

        /// @brief the global transform describes the positional information relative to the whole scene coordinates
        /// @return the transform for the current object relative to the scene root (world coordinates)
        glm::mat4 GetModelTransform() const;

        Entity() = default;
        ~Entity() = default;

        /// @brief Add a component to the current entity. Nothing happens if the component already exists
        /// @param component component to add to the current entity
        void AddComponent(Component *component);

    private:
        uint32_t id;
        std::vector<Component *> components;
    };

}
