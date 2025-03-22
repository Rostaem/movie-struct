cmake_minimum_required(VERSION 3.30)
project(movie_struct)

set(CMAKE_CXX_STANDARD 20)

# Add include directories for src/ and utils/
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/utils)

# Specify the executable and source files
add_executable(movie_struct
        main.cpp
        src/movie.cpp
        utils/input_validation.cpp
        utils/menu_option.cpp
)