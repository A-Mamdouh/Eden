#include "Window.hpp"
#include <raylib-cpp.hpp>

namespace Eden
{
    namespace Rendering
    {
        namespace Backend
        {
            namespace Raylib
            {
                namespace Implementation
                {
                    class Window : public Eden::Rendering::Backend::Raylib::Window
                    {
                    public:
                        Window(Eden::AppConfig &config)
                            : Eden::Rendering::Backend::Raylib::Window(config), width{config.rendererConfig.windowConfig.width.value_or(640)}, height{config.rendererConfig.windowConfig.width.value_or(480)}, window{int(width), int(height), config.name}, fullscreen{false}
                        {
                            auto confWidth = config.rendererConfig.windowConfig.width;
                            auto confHeight = config.rendererConfig.windowConfig.height;
                            auto confFullscreen = config.rendererConfig.windowConfig.fullscreen;
                            if (!(confFullscreen || (confWidth.has_value() && confHeight.has_value())))
                            {
                                throw std::runtime_error("Cannot create window with no size and without fullscreen");
                            }
                            if (confFullscreen)
                            {
                                int monitor = GetCurrentMonitor();
                                if (!confWidth.has_value())
                                {
                                    SetWidth(GetMonitorWidth(monitor));
                                    config.rendererConfig.windowConfig.width = this->width;
                                }
                                if (!confHeight.has_value())
                                {
                                    SetHeight(GetMonitorHeight(monitor));
                                    config.rendererConfig.windowConfig.height = this->height;
                                }
                            }
                            SetFullscreen(confFullscreen);
                        }

                        ~Window() = default;
                        Unique(Window);

                        virtual void SetWidth(const unsigned int width) override
                        {
                            window.SetSize({float(width), float(height)});
                            this->width = width;
                        }
                        virtual void SetHeight(const unsigned int height) override
                        {
                            window.SetSize({float(width), float(height)});
                            this->height = height;
                        }
                        virtual void SetFullscreen(const bool fullscreen) override
                        {
                            if (this->fullscreen != fullscreen)
                            {
                                window.ToggleBorderless();
                                // Handle resolution changes
                                this->fullscreen = fullscreen;
                            }
                        }
                        virtual unsigned int GetWidth() const override
                        {
                            return width;
                        }
                        virtual unsigned int GetHeight() const override
                        {
                            return height;
                        }
                        virtual bool IsFullscreen() const override
                        {
                            return fullscreen;
                        }
                        virtual bool ShouldClose() const override
                        {
                            return window.ShouldClose();
                        }
                        virtual void PollEvents() override
                        {
                            PollInputEvents();
                        }

                    private:
                        unsigned int width, height;
                        raylib::Window window;
                        bool fullscreen;
                    };
                }

                Window::Window(Eden::AppConfig &config)
                    : Eden::Rendering::Window(config) {}

                std::unique_ptr<Window> Window::Create(Eden::AppConfig &config)
                {
                    return std::make_unique<Implementation::Window>(config);
                }
            }
        }
    }
}