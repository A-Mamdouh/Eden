#include <Eden/Eden.hpp>
#include <iostream>

std::ostream & PrintVector(std::ostream &stream, const glm::vec3 vector)
{
    return stream << vector.x << " " << vector.y << " " << vector.z << std::endl;
}

int main()
{
    try{
        Eden::SceneSystem sceneSystem;
        auto entity = sceneSystem.CreateObject({.translation{100.0f, 10.0f, 0.0f}});
        auto entity2 = sceneSystem.CreateObject(entity, {.translation{200.0f, 10.0f, 0.0f}});

        auto transform = entity->GetLocalTransform();
        PrintVector(std::cout, transform.translation);
        PrintVector(std::cout, transform.scale);
        PrintVector(std::cout, transform.rotation);

        transform = entity2->GetLocalTransform();
        PrintVector(std::cout, transform.translation);
        PrintVector(std::cout, transform.scale);
        PrintVector(std::cout, transform.rotation);

        auto transform2 = entity->GetModelTransform();
        for(int i=0; i<4; ++i)
        {
            for(int j=0; j<4; ++j)
            {
                std::cout << transform2[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        transform2 = entity2->GetModelTransform();
        for(int i=0; i<4; ++i)
        {
            for(int j=0; j<4; ++j)
            {
                std::cout << transform2[i][j] << " ";
            }
            std::cout << std::endl;
        }

    } catch(std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
}