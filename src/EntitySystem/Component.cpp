#include <Eden/EntitySystem/Component.hpp>


namespace Eden { namespace Entities { namespace Components {

    const size_t Component::S_GetType() {
        return std::hash<std::string>{}("Component");
    }

    const size_t Component::GetType() {
        return S_GetType();
    }

    const std::string Component::S_GetTypeName() {
        return "Component";
    }

    const std::string Component::GetTypeName() {
        return S_GetTypeName();
    }

    const bool Component::IsComponentType(const size_t other_type) {
        return other_type == GetType();
    }

}}}