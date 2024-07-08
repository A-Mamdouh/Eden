#pragma once
#include <Eden/Core/Core.hpp>
#include <Eden/Core/Entity.hpp>
#include <Eden/Core/Component.hpp>
#include <Eden/Rendering/Mesh.hpp>

namespace Eden
{
    namespace Rendering
    {
        class Model : public EdenResource<Model>
        {
        public:
            static std::unique_ptr<Model> Create() { return nullptr; }
            ~Model() = default;
            UniqueResource(Model);

        protected:
            Model();

        private:
            std::vector<std::shared_ptr<Mesh>> meshes;
            std::vector<std::shared_ptr<Texture>> textures;
        };
    }
}