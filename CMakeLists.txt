cmake_minimum_required(VERSION 3.20)
project(Mazes)

find_package(glfw3 3.4 REQUIRED)

find_package(OpenGL REQUIRED)

add_executable(Mazes)

target_include_directories(Mazes PUBLIC src/headers)#where are the headers stored

target_sources(Mazes
    PRIVATE
        src/main.cpp
        src/source/Grid.cpp
        src/source/Cell.cpp
        src/source/Passage.cpp
)
target_link_libraries(Mazes glfw)
target_link_libraries(Mazes OpenGL::GL)

