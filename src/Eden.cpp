#include <Eden/Eden.hpp>
#include <iostream>

std::ostream & PrintVector(std::ostream &stream, const glm::vec3 vector)
{
    return stream << vector.x << " " << vector.y << " " << vector.z << std::endl;
}

void Example()
{
    Eden::SceneSystem sceneSystem;
    auto entity = sceneSystem.CreateObject({.translation{100.0f, 10.0f, 0.0f}});
    auto entity2 = sceneSystem.CreateObject(entity, {.translation{200.0f, 10.0f, 0.0f}});
    Eden::AppConfig config{
        .rendererConfig{
            .api{Eden::Rendering::RenderingAPI::Raylib},
            .windowConfig{
                .fullscreen{true}}}};
    auto renderer = Eden::Rendering::Renderer::Create(config);
    auto window = renderer->GetWindow();
    while (!window->ShouldClose())
    {
        window->PollEvents();
    }
}

int main()
{
    try
    {
        Example();
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
}