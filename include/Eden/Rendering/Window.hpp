#pragma once
#include <Eden/Core.hpp>
#include <Eden/Rendering/RenderingAPI.hpp>

namespace Eden { namespace Rendering {

    struct WindowConfig {
    public:
        const std::string windowName = "";
        const int width = -1;
        const int height = -1;
        const bool fullscreen = true;
    };


    class Window {
    public:
        
        virtual ~Window();
        EDEN_RAIIL(Window)
        
        const int GetHeight() { return height; }
        const int GetWidth() { return width; }
        const bool IsFullscreen() { return fullscreen; }
        const std::string GetName() { return windowName; }

    protected:
        Window(const std::shared_ptr<WindowConfig> &config);
        int width;
        int height;
        std::string windowName;
        bool fullscreen;
    };

}}