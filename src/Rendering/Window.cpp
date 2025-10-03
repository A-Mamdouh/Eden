#include <Eden/Rendering/Window.hpp>

namespace Eden
{
    namespace Rendering
    {
        Window::Window(Eden::AppConfig &config) : api{config.rendererConfig.api} {}

        std::unique_ptr<Window> Window::Create(Eden::AppConfig &config)
        {
            switch (config.rendererConfig.api)
            {
            case (RenderingAPI::Vulkan):
            {
                throw std::runtime_error("Vulkan window is not implemented yet");
            }
            default:
                throw std::runtime_error("Unknown rendering API");
            }
        }
    }
}