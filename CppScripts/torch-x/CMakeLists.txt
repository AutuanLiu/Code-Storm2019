cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(torch-x)

find_package(Torch REQUIRED)

add_executable(torch-x mnist.cpp)
target_compile_features(torch-x PUBLIC cxx_range_for)
target_link_libraries(torch-x "${TORCH_LIBRARIES}")
set_property(TARGET torch-x PROPERTY CXX_STANDARD 11)
