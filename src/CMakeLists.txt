list(APPEND eden_sources Eden.cpp)
list(APPEND eden_headers "${CMAKE_SOURCE_DIR}/include/Eden/Eden.hpp")

# Add Core
list(APPEND eden_headers
"${CMAKE_SOURCE_DIR}/include/Eden/Core/Component.hpp"
  "${CMAKE_SOURCE_DIR}/include/Eden/Core/Core.hpp"
  "${CMAKE_SOURCE_DIR}/include/Eden/Core/AppConfig.hpp"
  "${CMAKE_SOURCE_DIR}/include/Eden/Core/Entity.hpp"
  "${CMAKE_SOURCE_DIR}/include/Eden/Core/Transform.hpp"
)

list(APPEND eden_sources
"${CMAKE_SOURCE_DIR}/src/Core/Component.cpp"
"${CMAKE_SOURCE_DIR}/src/Core/Entity.cpp"
  "${CMAKE_SOURCE_DIR}/src/Core/Transform.cpp"
)

# Add Scene System
list(APPEND eden_headers
  "${CMAKE_SOURCE_DIR}/include/Eden/Scene/SceneComponents.hpp"
  "${CMAKE_SOURCE_DIR}/include/Eden/Scene/SceneSystem.hpp"
)

list(APPEND eden_sources
  "${CMAKE_SOURCE_DIR}/src/Scene/SceneComponents.cpp"
  "${CMAKE_SOURCE_DIR}/src/Scene/SceneSystem.cpp"
)

# Add Rendering System
list(APPEND eden_headers
"${CMAKE_SOURCE_DIR}/include/Eden/Rendering/Colors.hpp"
"${CMAKE_SOURCE_DIR}/include/Eden/Rendering/Mesh.hpp"
"${CMAKE_SOURCE_DIR}/include/Eden/Rendering/Model.hpp"
"${CMAKE_SOURCE_DIR}/include/Eden/Rendering/Renderer.hpp"
"${CMAKE_SOURCE_DIR}/include/Eden/Rendering/RenderingAPI.hpp"
"${CMAKE_SOURCE_DIR}/include/Eden/Rendering/Window.hpp"
)

list(APPEND eden_sources
  "${CMAKE_SOURCE_DIR}/src/Rendering/Window.cpp"
  "${CMAKE_SOURCE_DIR}/src/Rendering/Renderer.cpp"
)

add_library(eden ${eden_headers} ${eden_sources})

# Find opengl library
find_package(OpenGL REQUIRED)

# Add source files
target_include_directories(eden PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(eden PUBLIC glm assimp)
target_link_libraries(eden PRIVATE spdlog)

# Precompiled headers
target_precompile_headers(eden
  PUBLIC "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/pch_public.hpp>"
  PRIVATE "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/pch_private.hpp>"
)

# Set C++ standard
target_compile_features(eden PUBLIC cxx_std_20)