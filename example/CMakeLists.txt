project(
    EdenExample
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Example project using Eden"
)

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE eden)
