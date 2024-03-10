#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <Rendering/Backend/RendererVulkan.hpp>

namespace Eden { namespace Rendering { namespace Backend {
    
    RendererVulkan::RendererVulkan(const std::shared_ptr<RendererConfig> &config)
        : Renderer{config}
        , window(nullptr)
    {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        window = std::make_unique<WindowVulkan>(config->windowConfig);
    }

    bool RendererVulkan::IsAlive() { return !window->ShouldClose(); }

    void RendererVulkan::Update()
    {   
        window->SwapBuffers();
        window->PollEvents();
    }

    RendererVulkan::~RendererVulkan()
    {

    }

}}}