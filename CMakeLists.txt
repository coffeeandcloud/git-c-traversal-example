cmake_minimum_required(VERSION 3.13)  # CMake version check
project(simple_example)      


add_library(
    user-lib
    config.h
    config.c
)

set(GIT2_INCLUDE_DIRS /usr/local/Cellar/libgit2/1.1.0/include)
set(GIT2_LIBRARIES /usr/local/Cellar/libgit2/1.1.0/lib/libgit2.dylib)


# Add executable target with source files listed in SOURCE_FILES variable
add_executable(simple_example main.c)

target_link_libraries(simple_example ${GIT2_LIBRARIES})
target_include_directories(simple_example PUBLIC ${GIT2_INCLUDE_DIRS})
