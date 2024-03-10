#pragma once
#include <Eden/Core.hpp>
#include <Eden/Rendering/RenderingAPI.hpp>
#include <Eden/Rendering/Window.hpp>

namespace Eden { namespace Rendering {

    struct RendererConfig {
    public:
        const RenderingAPI& api;
        const std::shared_ptr<WindowConfig> windowConfig;
    };


    class Renderer {
    public:
        Renderer(const std::shared_ptr<RendererConfig> &config);
        ~Renderer();
        EDEN_RAIIL(Renderer)
        virtual void Update() = 0;
        virtual bool IsAlive() = 0;
        const RenderingAPI& GetAPI();

    private:
        const RenderingAPI &api;
    };

    extern std::unique_ptr<Renderer> CreateRenderer(const std::shared_ptr<RendererConfig> &config);

}}