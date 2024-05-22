#include "Renderer.hpp"
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
                    class Renderer : public Eden::Rendering::Backend::Raylib::Renderer
                    {
                    public:
                        Renderer(Eden::AppConfig &config)
                            : window{Eden::Rendering::Window::Create(config)}
                        {
                        }

                        void DrawScene() override
                        {
                        }

                        Model *CreateModel(Entity *owner, const std::string modelFilePath) override
                        {
                            return nullptr;
                        }

                        Window *GetWindow() override
                        {
                            return window.get();
                        }

                        ~Renderer() = default;
                        Unique(Renderer);

                    private:
                        std::unique_ptr<Window> window;
                    };
                }

                std::unique_ptr<Renderer> Renderer::Create(Eden::AppConfig &config)
                {
                    return std::make_unique<Implementation::Renderer>(config);
                }
            }
        }
    }
}