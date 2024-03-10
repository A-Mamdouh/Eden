#include <Eden/Eden.hpp>
#include <GLFW/glfw3.h>

int main() {
    try{
        spdlog::info("Calling run");
        Run();
        spdlog::info("Application finished");
    } catch(std::exception e) {
        spdlog::critical("Error: {}", e.what());
    }
}