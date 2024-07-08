add_executable(EdenTest ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp)
target_link_libraries(EdenTest eden)
target_link_libraries(EdenTest gtest)