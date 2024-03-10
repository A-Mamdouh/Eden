#pragma once
#include <Eden/Core.hpp>
#include <Rendering/Backend/WindowOpenGL.hpp>
#include <Eden/Rendering/Renderer.hpp>

namespace Eden { namespace Rendering { namespace Backend {
    class RendererOpenGL : public Renderer {
    public:
        RendererOpenGL(const std::shared_ptr<RendererConfig> &config);
        
        void Update() override;
        bool IsAlive() override;
        
        ~RendererOpenGL();
        EDEN_RAIIL(RendererOpenGL)

    private:
        std::unique_ptr<WindowOpenGL> window;
    };
}}}
