cmake_minimum_required(VERSION 3.24)
file(GLOB_RECURSE SOURCES "*.cpp" ".h")

add_library(SLAE_METHODS SHARED ${SOURCES})
