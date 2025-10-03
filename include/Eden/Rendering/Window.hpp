#pragma once

#include <Eden/Core/Core.hpp>
#include <Eden/Core/AppConfig.hpp>
#include "RenderingAPI.hpp"
#include <Eden/Rendering/Colors.hpp>

namespace Eden
{
    namespace Rendering
    {
        class Window : public EdenResource<Window>
        {
        public:
            static std::unique_ptr<Window> Create(Eden::AppConfig &config);

            virtual ~Window() = default;
            UniqueResource(Window);
            const RenderingAPI GetAPI() { return api; };
            virtual void SetWidth(const unsigned int width) = 0;
            virtual void SetHeight(const unsigned int height) = 0;
            virtual void SetFullscreen(const bool fullscreen) = 0;
            virtual unsigned int GetWidth() const = 0;
            virtual unsigned int GetHeight() const = 0;
            virtual bool IsFullscreen() const = 0;
            virtual bool ShouldClose() const = 0;
            virtual void PollEvents() = 0;
            virtual void ClearBackground(Rendering::Colors::Color color) = 0;
            virtual void BeginDrawing() = 0;
            virtual void EndDrawing() = 0;

        protected:
            Window(Eden::AppConfig &config);
            const RenderingAPI api;
        };
    }
}
