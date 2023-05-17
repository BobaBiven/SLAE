cmake_minimum_required(VERSION 3.24)
project(SLAE)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall)

# add_executable(SLAE main.cpp)
# target_link_libraries(SLAE SLAE_METHODS)

add_subdirectory(src)
add_subdirectory(tests)



