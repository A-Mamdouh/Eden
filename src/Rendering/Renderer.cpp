#include <Eden/Rendering/Renderer.hpp>

namespace Eden
{
    namespace Rendering
    {

        std::unique_ptr<Renderer> Renderer::Create(Eden::AppConfig &config)
        {
            switch (config.rendererConfig.api)
            {
            case (RenderingAPI::Vulkan):
            {
                throw std::runtime_error("Vulkan renderer is not implemented yet");
            }
            default:
                throw std::runtime_error("Unknown rendering API");
            }
        }
    }
}