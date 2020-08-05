cmake_minimum_required(VERSION 3.16)
project(midi_parser)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(./lib)

add_executable(midi_parser main.cpp)
target_link_libraries(midi_parser libParser)
