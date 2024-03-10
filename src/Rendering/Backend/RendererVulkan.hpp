#pragma once
#include <Eden/Core.hpp>
#include <Rendering/Backend/WindowVulkan.hpp>
#include <Eden/Rendering/Renderer.hpp>

namespace Eden { namespace Rendering { namespace Backend {
    class RendererVulkan : public Renderer {
    public:
        RendererVulkan(const std::shared_ptr<RendererConfig> &config);

        void Update() override;
        bool IsAlive() override;

        ~RendererVulkan();
        EDEN_RAIIL(RendererVulkan)
    
    private:
        std::unique_ptr<WindowVulkan> window;
    };
}}}