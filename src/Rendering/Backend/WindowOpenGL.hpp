#pragma once
#include <Eden/Core.hpp>
#include <Eden/Rendering/Window.hpp>
#include <GLFW/glfw3.h>

namespace Eden { namespace Rendering { namespace Backend {

    class WindowOpenGL : public Window {
    public:
        WindowOpenGL(const std::shared_ptr<WindowConfig> &config);
        bool ShouldClose();
        void SwapBuffers();
        void PollEvents();


        ~WindowOpenGL();
        EDEN_RAIIL(WindowOpenGL)
    private:
        GLFWwindow* pWindowOpenGL;
    };

}}}