#pragma once
#include <Eden/Rendering/RenderingAPI.hpp>
#include <Eden/Rendering/Window.hpp>

namespace Eden
{
    namespace Rendering
    {
        namespace Backend
        {
            namespace Raylib
            {
                /// @brief This is a wrapper to the implementation of a Raylib window. The implementation is a subclass
                /// This is an intentional design choice to keep Raylib internals from poluting the global namespace. This way, only the source files need to include raylib headers
                /// To create a new window, use the Create function which will return a unique pointer to the implemented class (which is RAII conforming)
                class Window : public Eden::Rendering::Window
                {
                public:
                    static std::unique_ptr<Window> Create(Eden::AppConfig &config);

                protected:
                    Window(Eden::AppConfig &config);
                };
            }
        }
    }
}