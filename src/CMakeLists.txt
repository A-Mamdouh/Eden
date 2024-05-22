list(APPEND eden_sources Eden.cpp)
list(APPEND eden_headers "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Eden.hpp>")

# Add Core
list(APPEND eden_headers
"$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Core/Component.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Core/Core.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Core/AppConfig.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Core/Entity.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Core/Transform.hpp>"
)

list(APPEND eden_sources
"$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Core/Component.cpp>"
"$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Core/Entity.cpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Core/Transform.cpp>"
)

# Add Scene System
list(APPEND eden_headers
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Scene/SceneComponents.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Scene/SceneSystem.hpp>"
)

list(APPEND eden_sources
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Scene/SceneComponents.cpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Scene/SceneSystem.cpp>"
)

# Add Rendering System
list(APPEND eden_headers
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Rendering/Window.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Rendering/Model.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Rendering/Mesh.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Rendering/Renderer.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include/Eden/Rendering/RenderingAPI.hpp>"
)

list(APPEND eden_sources
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Rendering/Window.cpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Rendering/Renderer.cpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Rendering/Backend/Raylib/Window.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Rendering/Backend/Raylib/Window.cpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Rendering/Backend/Raylib/Renderer.hpp>"
  "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/src/Rendering/Backend/Raylib/Renderer.cpp>"
)

add_library(eden ${eden_headers} ${eden_sources})

# Find opengl library
find_package(OpenGL REQUIRED)

# Add source files
target_include_directories(eden PUBLIC
                          "${eden_SOURCE_DIR}/include"
                          "${CMAKE_CURRENT_SOURCE_DIR}"
                          "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
                        )

target_link_libraries(eden PUBLIC glm assimp)
target_link_libraries(eden PRIVATE glm spdlog raylib raylib_cpp)

# Precompiled headers
target_precompile_headers(eden
PUBLIC
  "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/pch_public.hpp>"
PRIVATE
  "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/pch_private.hpp>"
)

# Set C++ standard
target_compile_features(eden PUBLIC cxx_std_20)
set_target_properties(eden PROPERTIES CXX_EXTENSIONS OFF)

# Set DLL position independent code
set_target_properties(eden PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Link time optimization
include(CheckIPOSupported)
check_ipo_supported(RESULT result)
if(result)
  set_target_properties(eden PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()