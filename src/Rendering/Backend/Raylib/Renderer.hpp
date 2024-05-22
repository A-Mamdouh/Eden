#pragma once
#include <Eden/Rendering/RenderingAPI.hpp>
#include <Eden/Rendering/Renderer.hpp>

namespace Eden
{
    namespace Rendering
    {
        namespace Backend
        {
            namespace Raylib
            {
                /// @brief This is a wrapper to the implementation of a Raylib Renderer. The implementation is a subclass
                /// This is an intentional design choice to keep Raylib internals from poluting the global namespace. This way, only the source files need to include raylib headers
                /// To create a new Renderer, use the Create function which will return a unique pointer to the implemented class (which is RAII conforming)
                class Renderer : public Eden::Rendering::Renderer
                {
                public:
                    static std::unique_ptr<Renderer> Create(Eden::AppConfig &config);

                protected:
                    Renderer() = default;
                };
            }
        }
    }
}