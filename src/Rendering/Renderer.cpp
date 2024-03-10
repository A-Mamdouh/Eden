#include <Rendering/Backend/RendererOpenGL.hpp>
#include <Rendering/Backend/RendererVulkan.hpp>
#include <Eden/Rendering/Renderer.hpp>

namespace Eden { namespace Rendering {
    Renderer::Renderer(const std::shared_ptr<RendererConfig> &config)
        : api{config->api}
    {}

    Renderer::~Renderer() {}

    const RenderingAPI& Renderer::GetAPI() { return api; }

    std::unique_ptr<Renderer> CreateRenderer(const std::shared_ptr<RendererConfig> &config) {
        switch(config->api) {
            case(RenderingAPI::OpenGL) : return std::make_unique<Backend::RendererOpenGL>(config);
            case(RenderingAPI::Vulkan) : return std::make_unique<Backend::RendererVulkan>(config);
            default: throw std::runtime_error(std::string("Unknown rendering API: ") + std::to_string(static_cast<uint8_t>(config->api)));
        }
    }
}}