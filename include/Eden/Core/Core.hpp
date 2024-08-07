#pragma once

#define NoCopy(X)          \
    X(const X &) = delete; \
    X operator=(const X &) = delete;
#define NoMove(X)           \
    X(const X &&) = delete; \
    X operator=(const X &&) = delete;
#define UniqueResource(X) NoCopy(X) NoMove(X)

namespace Eden
{

    /// @brief This should be the base class for allocated resources of Eden.
    /// every resource type has to extend this class for the Create function to work
    template <typename T>
    struct EdenResource
    {
        const uint64_t id;
        UniqueResource(EdenResource);
        ~EdenResource() = default;

        template <class... Args>
        static auto New(Args &&...args) -> std::unique_ptr<T>
        {
            return std::make_unique<T>(std::forward<Args>(args)...);
        }

    protected:
        EdenResource()
            : id{CreateID()}
        {
        }

    private:
        /// @brief Create ID @warning not thread safe
        /// @return a new ID
        uint64_t CreateID()
        {
            static uint64_t id = 0;
            return id++;
        }
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

    /// @copydoc IsInstance
    template <typename Type, typename InstanceType>
    inline bool IsInstance(std::shared_ptr<InstanceType> &instance)
    {
        return std::dynamic_pointer_cast<Type>(instance) != nullptr;
    }

    /// @copydoc IsInstance
    template <typename Type, typename InstanceType>
    inline bool IsInstance(const std::shared_ptr<InstanceType> &instance)
    {
        InstanceType *rawPtr = const_cast<InstanceType *>(instance.get());
        return dynamic_cast<Type*>(rawPtr) != nullptr;
    }

    /// @copydoc IsInstance
    template <typename Type, typename InstanceType>
    inline bool IsInstance(const InstanceType &instance)
    {
        InstanceType *rawPtr = const_cast<InstanceType *>(&instance);
        return dynamic_cast<Type*>(rawPtr) != nullptr;
    }

}
