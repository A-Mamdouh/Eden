#include <Eden/Rendering/Window.hpp>
#include "Backend/Raylib/Window.hpp"

namespace Eden
{
    namespace Rendering
    {
        Window::Window(Eden::AppConfig &config) : api{config.rendererConfig.api} {}

        std::unique_ptr<Window> Window::Create(Eden::AppConfig &config)
        {
            switch (config.rendererConfig.api)
            {
            case (RenderingAPI::Raylib):
            {
                return Backend::Raylib::Window::Create(config);
            }
            default:
                throw std::runtime_error("Unknown rendering API");
            }
        }
    }
}