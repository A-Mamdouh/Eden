#pragma once
#include <Eden/Core/Core.hpp>
#include <Eden/Core/Entity.hpp>
#include <Eden/Core/Component.hpp>
#include <Eden/Rendering/Mesh.hpp>

namespace Eden
{
    namespace Rendering
    {
        class Model : public EdenResource
        {
        public:
            static std::unique_ptr<Model> Create() { return nullptr; }
            ~Model() = default;
            Unique(Model);

        protected:
            Model();

        private:
            std::vector<Mesh *> meshes;
            std::vector<Texture *> textures;
        };
    }
}