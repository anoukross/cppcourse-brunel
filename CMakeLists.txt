project (Neuron)
cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11 -g")

enable_testing()
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})



add_executable (Neuron Neuron.cpp Network.cpp Experiment.cpp main.cpp)
add_executable (Unittest Network.cpp Neuron.cpp Experiment Unittest.cpp Unittestmain.cpp)

target_link_libraries(Unittest gtest gtest_main)
add_test(Unittest Unittest)