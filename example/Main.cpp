#include <Eden/Eden.hpp>

void ExampleRenderer() {
    auto rendererConfig = std::make_shared<Eden::Rendering::RendererConfig>(
        // Rendering API
        Eden::Rendering::RenderingAPI::Vulkan,
        // Window config
        std::make_shared<Eden::Rendering::WindowConfig>(
            "Eden Example",
            800,
            600,
            false
        )
    );
    auto renderer = Eden::Rendering::CreateRenderer(rendererConfig);
    while(renderer->IsAlive()) {
        renderer->Update();
    }
}

void Run() {
    ExampleRenderer();
}
