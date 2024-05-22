#pragma once
#include <Eden/Core/Core.hpp>
#include <Eden/Rendering/RenderingAPI.hpp>

namespace Eden
{

    struct WindowConfig
    {
        // Window height in pixels. If not set, fullscreen has to be on
        std::optional<unsigned int> height = {};
        // Window width in pixels. If not set, fullscreen has to be on
        std::optional<unsigned int> width = {};
        // Window monitor. If not set, the primary monitor will be chosen and saved
        std::optional<unsigned int> monitor = {};
        /** Window fullscreen state.
         * If false, height and width must be set
         * If true and height is not set, height will match the monitor resolution
         * If true and width is not set, width will match the monitor resolution
         **/
        bool fullscreen = true;
    };

    struct RendererConfig
    {
        Eden::Rendering::RenderingAPI api;
        WindowConfig windowConfig;
    };

    struct AppConfig
    {
        const std::string name;
        RendererConfig rendererConfig;
    };
}