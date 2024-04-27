#pragma once
#include <Eden/Core/Core.hpp>

namespace Eden
{
    struct Transform
    {
    public:
        glm::vec3 translation = glm::vec3(0.0f);
        glm::vec3 scale = glm::vec3(1.0f);
        glm::vec3 rotation = glm::vec3(0.0f);

        /// @brief Get a single matrix representing this transform
        /// @param from starting transform. Default to identity (no previous transform)
        /// @return transform matrix afer applying this transform
        glm::mat4 GetMat(glm::mat4 from = glm::identity<glm::mat4>()) const;

        /// @copybrief Eden::Transform::GetMat
        /// @param from starting transform. Default to identity (no previous transform)
        /// @return transform matrix afer applying this transform
        glm::mat4 GetMat(const Transform from) const;

        /// @brief Apply transform to a point
        /// @param from point to apply the transform to. Defaults to the origin
        /// @return 4D homogenous coordinate of the resulting transform
        glm::vec4 GetPoint(glm::vec3 from = glm::vec3(0.0f)) const;
    };
}