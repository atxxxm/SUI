cmake_minimum_required(VERSION 3.10)

project(SUI)

add_executable(ui src/main.cpp)
add_library(func src/sui_func.cpp)
add_library(draw src/draw.cpp)
add_library(window src/window.cpp)

target_link_libraries(
    ui
    draw
    window
    func
    sfml-graphics
    sfml-window
    sfml-audio
    sfml-system
)