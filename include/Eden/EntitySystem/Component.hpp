#pragma once

#define DECL_COMPONENT( x ) \
        virtual const size_t GetType() override { return std::hash<std::string>{}(#x); } \
        static const size_t S_GetType() { return std::hash<std::string>{}(#x); } \
        virtual const bool IsComponentType(const size_t other_type) override { return other_type == GetType(); } \
        virtual const std::string GetTypeName() override { return #x; } \
        static const std::string S_GetTypeName() { return #x; }


namespace Eden { namespace Entities { namespace Components {
    class Component {
        public:
        virtual const size_t GetType();
        static const size_t S_GetType();
        virtual const bool IsComponentType(const size_t other_type);
        virtual const std::string GetTypeName();
        static const std::string S_GetTypeName();

        // Destructor
        virtual ~Component() = default;
        // Copy control
        Component(Component &other) = delete;
        Component(Component &&other) = delete;
        Component operator=(Component &other) = delete;
        Component operator=(Component &&other) = delete;
        // Only cloneable using clone 
        virtual Component Clone() = 0;
    };
}}}