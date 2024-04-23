#pragma once

#define NoCopy(X)          \
    X(const X &) = delete; \
    X operator=(const X &) = delete;
#define NoMove(X)           \
    X(const X &&) = delete; \
    X operator=(const X &&) = delete;
#define Unique(X) NoCopy(X) NoMove(X)

namespace Eden
{

    /// @brief This should be the base class for allocated resources of Eden.
    /// very resource type has to extend this class for the Create function to work
    class EdenResource
    {
    };

    /// @brief Checks if an object is of the template type
    /// @tparam Type Type to check against
    /// @tparam InstanceType type of passed instance
    /// @param instance instance to check the type of
    /// @return true if instance is of type Type (using dynamic types)
    template <typename Type, typename InstanceType>
    inline bool IsInstance(InstanceType *instance)
    {
        return dynamic_cast<Type *>(instance) != nullptr;
    }

    /// @brief Checks if an object is of the template type (smart pointer instance)
    /// @tparam Type Type to check against
    /// @tparam InstanceType type of passed instance
    /// @param instance instance to check the type of
    /// @return true if instance is of type Type (using dynamic types)
    template <typename Type, typename InstanceType>
    inline bool IsInstance(std::shared_ptr<InstanceType> &instance)
    {
        return std::dynamic_pointer_cast<Type>(instance) != nullptr;
    }

    /// @brief Create an instance of ResourceType
    /// @tparam ResourceType The type of resource to create
    /// @tparam ...ArgTypes List of types for the construtor of ResourceType (Optional)
    /// @param ...Args constructor parameters for type ResourceType
    /// @return a Unique pointer to an instance of type ResourceType
    template <typename ResourceType, typename... ArgTypes>
    // Asserting that ResourceType is an instance of Eden::ResourceType
        requires std::is_base_of<EdenResource, ResourceType>::value
    std::unique_ptr<ResourceType> Create(ArgTypes &&...Args)
    {
        return std::move(std::make_unique<ResourceType>(std::forward<ArgTypes>(Args)...));
    }

}
