#include <Eden/Rendering/Renderer.hpp>
#include "Backend/Raylib/Renderer.hpp"

namespace Eden
{
    namespace Rendering
    {

        std::unique_ptr<Renderer> Renderer::Create(Eden::AppConfig &config)
        {
            switch (config.rendererConfig.api)
            {
            case (RenderingAPI::Raylib):
            {
                return Backend::Raylib::Renderer::Create(config);
            }
            default:
                throw std::runtime_error("Unknown rendering API");
            }
        }
    }
}