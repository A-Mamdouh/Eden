#pragma once
#include <Eden/Core.hpp>
#include <Eden/Rendering/Window.hpp>
#include <GLFW/glfw3.h>

namespace Eden { namespace Rendering { namespace Backend {

    class WindowVulkan : public Window {
    public:
        WindowVulkan(const std::shared_ptr<WindowConfig> &config);
        bool ShouldClose();
        void SwapBuffers();
        void PollEvents();


        ~WindowVulkan();
        EDEN_RAIIL(WindowVulkan)
    private:
        GLFWwindow* pWindowVulkan;
    };

}}}