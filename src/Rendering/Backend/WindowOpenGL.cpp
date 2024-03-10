#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Rendering/Backend/WindowOpenGL.hpp>

namespace Eden { namespace Rendering { namespace Backend {
    WindowOpenGL::WindowOpenGL(const std::shared_ptr<WindowConfig> &config)
        : Window{config}
        , pWindowOpenGL{nullptr}
    {
        assert(!((height == -1) ^(width == -1)) && "Must define both height and width or set both to -1");
        assert(height >= -1 && "Height must be >= -1");
        assert(width >= -1 && "Width must be >= -1");
        if(!glfwInit()) {
            throw std::runtime_error("Could not initialize GLFW");
        }
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        if(height == -1) {
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            height = mode->height;
            width = mode->width;
        }
        if(!fullscreen) {
            monitor = nullptr;
        }
        pWindowOpenGL = glfwCreateWindow(width, height, windowName.c_str(), monitor, nullptr);
        if(pWindowOpenGL == nullptr) {
            throw std::runtime_error("Failed to create GLFW window");
        }
        glfwSetWindowUserPointer(pWindowOpenGL, this);
        glfwMakeContextCurrent(pWindowOpenGL);
    }

    WindowOpenGL::~WindowOpenGL() {
        if(pWindowOpenGL != nullptr) {
            glfwDestroyWindow(pWindowOpenGL);
        }
        glfwTerminate();
    }

    bool WindowOpenGL::ShouldClose() {
        return glfwWindowShouldClose(pWindowOpenGL);
    }

    void WindowOpenGL::SwapBuffers() {
        glfwSwapBuffers(pWindowOpenGL);
    }

    void WindowOpenGL::PollEvents() {
        glfwPollEvents();
    }
}}}
