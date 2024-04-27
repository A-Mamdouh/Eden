#include <Eden/Core/Transform.hpp>

namespace Eden
{
    glm::mat4 Transform::GetMat(glm::mat4 from) const
    {
        auto mat = glm::scale(from, scale);
        mat = glm::rotate(mat, rotation.x, {1.0, 0.0, 0.0}); // Rotation about x
        mat = glm::rotate(mat, rotation.y, {0.0, 1.0, 0.0}); // Rotation about y
        mat = glm::rotate(mat, rotation.z, {0.0, 0.0, 1.0}); // Rotation about z
        return glm::translate(mat, translation);
    }

    glm::mat4 Transform::GetMat(const Transform from) const
    {
        // Get starting matrix
        auto mat = glm::scale(from.GetMat(), scale);
        mat = glm::rotate(mat, rotation.x, {1.0, 0.0, 0.0}); // Rotation about x
        mat = glm::rotate(mat, rotation.y, {0.0, 1.0, 0.0}); // Rotation about y
        mat = glm::rotate(mat, rotation.z, {0.0, 0.0, 1.0}); // Rotation about z
        return glm::translate(mat, translation);
    }

    glm::vec4 Transform::GetPoint(glm::vec3 from) const
    {
        auto mat = glm::scale(glm::identity<glm::mat4>(), scale);
        mat = glm::rotate(mat, rotation.x, {1.0, 0.0, 0.0}); // Rotation about x
        mat = glm::rotate(mat, rotation.y, {0.0, 1.0, 0.0}); // Rotation about y
        mat = glm::rotate(mat, rotation.z, {0.0, 0.0, 1.0}); // Rotation about z
        return glm::translate(mat, translation) * glm::vec4(from, 1.0);
    }
}
