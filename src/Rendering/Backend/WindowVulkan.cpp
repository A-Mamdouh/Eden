#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <Rendering/Backend/WindowVulkan.hpp>

namespace Eden { namespace Rendering { namespace Backend {
    WindowVulkan::WindowVulkan(const std::shared_ptr<WindowConfig> &config)
        : Window{config}
        , pWindowVulkan{nullptr}
    {
        assert(!((height == -1) ^(width == -1)) && "Must define both height and width or set both to -1");
        assert(height >= -1 && "Height must be >= -1");
        assert(width >= -1 && "Width must be >= -1");
        if(!glfwInit()) {
            throw std::runtime_error("Could not initialize GLFW");
        }
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        if(height == -1) {
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            height = mode->height;
            width = mode->width;
        }
        if(!fullscreen) {
            monitor = nullptr;
        }
        pWindowVulkan = glfwCreateWindow(width, height, windowName.c_str(), monitor, nullptr);
        if(pWindowVulkan == nullptr) {
            throw std::runtime_error("Failed to create GLFW window");
        }
        glfwSetWindowUserPointer(pWindowVulkan, this);
        glfwMakeContextCurrent(pWindowVulkan);
    }

    WindowVulkan::~WindowVulkan() {
        if(pWindowVulkan != nullptr) {
            glfwDestroyWindow(pWindowVulkan);
        }
        glfwTerminate();
    }

    bool WindowVulkan::ShouldClose() {
        return glfwWindowShouldClose(pWindowVulkan);
    }

    void WindowVulkan::SwapBuffers() {
        glfwSwapBuffers(pWindowVulkan);
    }

    void WindowVulkan::PollEvents() {
        glfwPollEvents();
    }
}}}
