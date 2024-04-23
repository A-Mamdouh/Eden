#include <Eden/Eden.hpp>

int main()
{
    const auto entity = Eden::Create<Eden::Entity>();
    spdlog::info("Hello world! {}", entity->GetId());
}