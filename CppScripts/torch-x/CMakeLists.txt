cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(torch-x)

set(CMAKE_CXX_STANDARD 14)

#set libtorch path
set(TORCH_HOME "/home/lyc/Softwares/libtorch")
set(CMAKE_PREFIX_PATH ${TORCH_HOME})

find_package(Torch REQUIRED)

include_directories(${TORCH_HOME}/include/torch/csrc/api/include)
include_directories(${TORCH_HOME}/include)

add_executable(torch-x mnist.cpp)
target_compile_features(torch-x PUBLIC cxx_range_for)
target_link_libraries(torch-x "${TORCH_LIBRARIES}")
set_property(TARGET torch-x PROPERTY CXX_STANDARD 14)