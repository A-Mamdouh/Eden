set(eden_source
  Eden.cpp
  glad.c
  EntitySystem/Component.cpp
  EntitySystem/Entity.cpp
)

set(eden_HEADER_LOC "$<BUILD_INTERFACE:${eden_SOURCE_DIR}/include>")

set(eden_headers
  glad/glad.h
  KHR/khrplatform.h
  "${eden_HEADER_LOC}/Eden/Eden.hpp"
  "${eden_HEADER_LOC}/Eden/Core.hpp"
)
#####################################
### Renderer start ##################

# Add renderer headers
list(APPEND eden_headers
"${eden_HEADER_LOC}/Eden/Rendering/RenderingAPI.hpp"
"${eden_HEADER_LOC}/Eden/Rendering/Window.hpp"
"${eden_HEADER_LOC}/Eden/Rendering/Renderer.hpp"
)

# Add renderer source files
list(APPEND eden_source
  Rendering/Window.cpp
  Rendering/Backend/WindowOpenGL.hpp
  Rendering/Backend/WindowOpenGL.cpp
  Rendering/Backend/WindowVulkan.hpp
  Rendering/Backend/WindowVulkan.cpp
  Rendering/Backend/RendererOpenGL.hpp
  Rendering/Backend/RendererOpenGL.cpp
  Rendering/Backend/RendererVulkan.hpp
  Rendering/Backend/RendererVulkan.cpp
  Rendering/Renderer.cpp
)

### Renderer end ####################
#####################################

#####################################
### Entity System start #############

# Add ES headers
list(APPEND eden_headers
"${eden_HEADER_LOC}/Eden/EntitySystem/Scene.hpp"
)

# Add ES sources
# list(APPEND eden_source
# )


### Entity System end ###############
#####################################

# Create library target
add_library(eden ${eden_headers} ${eden_source})

# Find system libraries
find_package(OpenGL REQUIRED)
find_package(Vulkan REQUIRED)

# Add source files
target_include_directories(eden PUBLIC
                          "${eden_SOURCE_DIR}/include"
                          "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
                          )

target_include_directories(eden PRIVATE
                          "${CMAKE_CURRENT_SOURCE_DIR}"
                          "${eden_SOURCE_DIR}/src"
                          "${eden_BINARY_DIR}/src"
                          "${Vulkan_INCLUDE_DIR}"
                          )

target_link_libraries(eden PUBLIC glm)
target_link_libraries(eden PRIVATE spdlog glfw nlohmann_json ${Vulkan_LIBRARIES})

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

# C/++ options
set_target_properties(eden
PROPERTIES
    CXX_CLANG_TIDY ON
    CXX_CPPCHECK ON
    CXX_CPPLINT ON
)