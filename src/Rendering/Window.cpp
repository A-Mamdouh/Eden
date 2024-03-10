#include <Eden/Rendering/Window.hpp>


namespace Eden { namespace Rendering {

    Window::Window(const std::shared_ptr<WindowConfig> &config)
        : width{config->width}
        , height{config->height}
        , windowName{config->windowName}
        , fullscreen{config->fullscreen}
    {}

    Window::~Window() {}

}}