#pragma once

#include <Eden/Core/Core.hpp>
#include <Eden/Core/AppConfig.hpp>
#include "Window.hpp"
#include "Model.hpp"
#include "RenderingAPI.hpp"

namespace Eden
{
    namespace Rendering
    {
        class Renderer
        {
        public:
            /// @brief Return the window of the current renderer
            /// @return pointer to the current window
            virtual Window *GetWindow() = 0;

            /// @brief Draw the current scene using all the registered models
            virtual void DrawScene() = 0;

            /// @brief Load model from file and register it interally and to the owner entity
            /// @param owner the entity that this model is attached to
            /// @param modelFilePath path to the file containing the model
            /// @return a pointer to the loaded model
            virtual Model *CreateModel(Entity *owner, const std::string modelFilePath) = 0;

            /// @brief Create a new renderer
            /// @param api rendering api to use
            /// @return a unique pointer to the newly created renderer
            static std::unique_ptr<Renderer> Create(Eden::AppConfig &config);

            virtual ~Renderer() = default;
            Unique(Renderer);

        protected:
            Renderer() = default;
        };
    }
}