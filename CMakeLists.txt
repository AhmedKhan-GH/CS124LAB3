cmake_minimum_required(VERSION 3.5)

project(main)

set(CMAKE_CXX_STANDARD 11)

# Get a list of all the .cpp files in the folder
file(GLOB CPP_FILES "*.cpp")

# Create the executable
add_executable(main ${CPP_FILES})

