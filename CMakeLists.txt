cmake_minimum_required(VERSION 3.10)
project(Game_of_Life VERSION 1.0)
add_executable(Game_of_Life simulate.c)
add_subdirectory(life)
target_link_libraries(Game_of_Life PUBLIC The_Life)
target_include_directories(Game_of_Life PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/include"
)
