cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)
include(GoogleTest)
enable_testing()

file(GLOB TEST_SOURCES "*.cc")

add_executable(test ${TEST_SOURCES})

target_link_libraries(test PRIVATE gtest_main SLAE_METHODS)
target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR})

gtest_discover_tests(test)
