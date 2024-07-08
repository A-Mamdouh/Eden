cmake_minimum_required(VERSION 3.21...3.28)

# Define project
project(
    Eden
    VERSION 0.0.1
    DESCRIPTION "Simple Graphics Engine"
    LANGUAGES CXX
)

set(eden_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(eden_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(BUILD_SHARED_LIBS FALSE) 

# Define build options
option(BUILD_EXAMPLE "build example project" ON)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

## Install submodules
find_package(Git REQUIRED)

if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
    endif()
endif()

# Add external dependencies
set(BUILD_EXAMPLE_OLD ${BUILD_EXAMPLE})
set(BUILD_EXAMPLE OFF)
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/extern/glfw")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/extern/glfw/include")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/extern/glm")
set(ASSIMP_INSTALL OFF)
set(ASSIMP_BUILD_ASSIMP_VIEW OFF)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/extern/assimp")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/extern/spdlog")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/extern/raylib")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/extern/raylib-cpp")
set(BUILD_EXAMPLE ${BUILD_EXAMPLE_OLD})
# Add src
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

# Build optional modules
if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
    # Build example project
    if(BUILD_EXAMPLE)
        add_subdirectory(example)
    endif()
    # Testing
    if(BUILD_TESTING)
        add_subdirectory(extern/gtest)
        add_subdirectory(test)
    endif()
endif()
