set(eden_sources
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
  "${eden_HEADER_LOC}/Eden/EntitySystem/Component.hpp"
  "${eden_HEADER_LOC}/Eden/EntitySystem/Entity.hpp"
)

add_library(eden ${eden_headers} ${eden_sources})

# Find opengl library
find_package(OpenGL REQUIRED)

# Add source files
target_include_directories(eden PUBLIC
                          "${eden_SOURCE_DIR}/include"
                          "${CMAKE_CURRENT_SOURCE_DIR}"
                          "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_include_directories(glfw PRIVATE
                          "${eden_SOURCE_DIR}/src"
                          "${eden_BINARY_DIR}/src")

target_link_libraries(eden PUBLIC glm spdlog glfw nlohmann_json)

# Precompiled headers
target_precompile_headers(eden
PUBLIC
  "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/pch_public.hpp>"
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