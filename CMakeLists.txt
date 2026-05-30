cmake_minimum_required(VERSION 3.20)
project(Mazes)

find_package(glfw3 3.4 REQUIRED)

find_package(OpenGL REQUIRED)

add_executable(Mazes)

target_include_directories(Mazes PUBLIC src/headers, src/headers, src/headers)#where are the headers stored

target_sources(Mazes
    PRIVATE
        src/main.cpp
        src/source/mazeGen/binary_tree.cpp
        src/source/mazeGen/recursive_backtracker.cpp
        src/source/mazeGen/maze.cpp
        src/source/pathfinding/tree_search.cpp
        src/source/pathfinding/RHS.cpp
)
target_link_libraries(Mazes glfw)
target_link_libraries(Mazes OpenGL::GL)

