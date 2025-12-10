cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(
    tp-data
    DESCRIPTION "TP Data Structure"
    LANGUAGES C CXX
)

message("# Build configuration for ${CMAKE_PROJECT_NAME} with CMake ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++${CMAKE_CXX_STANDARD}")

message(STATUS "CXX Options: ${CMAKE_CXX_FLAGS}")

# Source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h*")

# Add executable target
add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

# Include directories
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_compile_options(${CMAKE_CXX_FLAGS})