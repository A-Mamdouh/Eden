#pragma once
#include <Eden/Core/Core.hpp>
#include <Eden/Core/Entity.hpp>
#include <Eden/Core/Component.hpp>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

namespace Eden
{
    struct Texture
    {
        unsigned int id;
        std::string type;
    };

    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texture;
    };

    namespace Rendering
    {
        class Mesh : public EdenResource<Mesh>
        {
        public:
            Mesh()
            {
                Assimp::Importer importer;
                const auto *scene = importer.ReadFile("model.obj", aiProcess_Triangulate | aiProcess_FlipUVs); // TODO: Move to cpp
            }

        private:
            std::vector<std::shared_ptr<Texture>> textures;
            std::vector<std::shared_ptr<Vertex>> vertices;
            std::vector<unsigned int> indices;
        };
    }
}