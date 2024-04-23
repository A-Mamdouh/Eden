#pragma once

#include <Eden/Core/Core.hpp>

namespace Eden
{

    class Component;

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
        std::optional<std::shared_ptr<ComponentType>> GetComponent()
        {
            auto found = std::find_if(components.begin(), components.end(), [](auto &component)
                                      { return IsInstance<ComponentType>(component); });
            // If component not found
            if (found == components.end())
            {
                return std::nullopt;
            }
            return *found;
        }

        /// @brief Get all components of a given type
        /// @tparam ComponentType Type of components to look for
        /// @return returns a vector of matching components
        template <class ComponentType>
        // Asserting that ComponentType is an instance of Eden::Component
            requires std::is_base_of<Component, ComponentType>::value
        std::vector<std::shared_ptr<ComponentType>> GetComponents()
        {
            auto result = components
                | std::ranges::views::filter([](auto &component) { return IsInstance<ComponentType>(component); })
                | std::ranges::views::transform([](auto &component) { return std::static_pointer_cast<ComponentType>(component); });
            return std::vector<std::shared_ptr<ComponentType>>(result.begin(), result.end());
        }

        Entity();
        ~Entity() = default;

        /// @brief Get the unique ID of an entity
        /// @return returns the ID of the entity
        const uint32_t GetId() const;

        /// @brief Add a component to the current entity. Nothing happens if the component already exists
        /// @param component component to add to the current entity
        void AddComponent(std::shared_ptr<Component> component);

    private:
        uint32_t id;
        std::vector<std::shared_ptr<Component>> components;
    };

}
