#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <Rendering/Backend/RendererOpenGL.hpp>

namespace Eden { namespace Rendering { namespace Backend {
    RendererOpenGL::RendererOpenGL(const std::shared_ptr<RendererConfig> &config)
        : Renderer{config}
        , window{std::make_unique<WindowOpenGL>(config->windowConfig)}
    {
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("failed to create GLFW renderer. failed to load glad");
        }
        // CreateSwapChain();
        // CreateImageViews();
        // CreateRenderPasses();
        // CreateGraphicsPipelines();
    }

    RendererOpenGL::~RendererOpenGL()
    {

    }

    void RendererOpenGL::Update()
    {
        glViewport(0, 0, window->GetWidth(), window->GetHeight());
        glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        window->SwapBuffers();
        window->PollEvents();
    }

    bool RendererOpenGL::IsAlive() {
        return !window->ShouldClose();
    }



}}}