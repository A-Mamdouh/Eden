cmake_minimum_required(VERSION 3.21)

# Define project
project(
    Eden
    VERSION 0.0.1
    DESCRIPTION "Simple Graphics Engine"
    LANGUAGES CXX
)

set(BUILD_SHARED_LIBS FALSE) 

## Install submodules
find_package(Git REQUIRED)

### dependencies

# spdlog
find_package(spdlog QUIET)
if (NOT spdlog_FOUND)
    if (NOT DEFINED SPDLOG_VERSION)
        set(SPDLOG_VERSION v1.15.3)
    endif()
    include(FetchContent)
    FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG ${SPDLOG_VERSION}
    )
    FetchContent_MakeAvailable(spdlog)
endif()

# glfw
find_package(glfw QUIET)
if (NOT glfw_FOUND)
    if (NOT DEFINED GLFW_VERSION)
        set(GLFW_VERSION 3.4)
    endif()
    include(FetchContent)
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG ${GLFW_VERSION}
    )
    FetchContent_MakeAvailable(glfw)
endif()

# vulkan
find_package(Vulkan QUIET)
if (NOT Vulkan_FOUND)
    if (NOT DEFINED VULKAN_VERSION)
        set(VULKAN_VERSION v1.4.328)
    endif()
    include(FetchContent)
    FetchContent_Declare(
        Vulkan
        GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Headers.git
        GIT_TAG ${VULKAN_VERSION}
    )
    FetchContent_MakeAvailable(Vulkan)
endif()

# assimp
find_package(assimp QUIET)
if (NOT assimp_FOUND)
    if (NOT DEFINED ASSIMP_VERSION)
        set(ASSIMP_VERSION v6.0.2)
    endif()
    include(FetchContent)
    FetchContent_Declare(
        assimp
        GIT_REPOSITORY https://github.com/assimp/assimp.git
        GIT_TAG ${ASSIMP_VERSION}
    )
    FetchContent_MakeAvailable(assimp)
endif()


# gtest
find_package(GTest QUIET)
if (NOT GTest_FOUND)
    if (NOT DEFINED GTEST_VERSION)
        set(GTEST_VERSION v1.17.0)
    endif()
    include(FetchContent)
    FetchContent_Declare(
        GTest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG ${GTEST_VERSION}
    )
    FetchContent_MakeAvailable(GTest)
endif()

add_subdirectory(src)
add_subdirectory(example)
