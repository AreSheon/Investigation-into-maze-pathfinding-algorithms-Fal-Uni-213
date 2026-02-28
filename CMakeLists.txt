cmake_minimum_required(VERSION 3.20)
project(Mazes)

find_package(glfw3 3.4 REQUIRED)

find_package(OpenGL REQUIRED)

add_executable(Mazes)

target_include_directories(Mazes PUBLIC src/headers)#where are the headers stored
target_sources(Mazes
    PRIVATE
        src/main.cxx
        src/scource/maze.cxx
        src/scource/depth_first.cxx
        src/scource/binary_tree.cxx
)

target_link_libraries(Mazes glfw)
target_link_libraries(Mazes OpenGL::GL)

