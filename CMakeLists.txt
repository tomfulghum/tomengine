cmake_minimum_required(VERSION 3.0)
project(tomengine)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(EXTERNAL_DIRECTORY "${CMAKE_SOURCE_DIR}/external")

# GLFW build settings
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCES 
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Entity/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/Utility/*.cpp"
)

add_library(tomengine OBJECT
    ${SOURCES}
    ${EXTERNAL_DIRECTORY}/glad/src/glad.c
)

target_include_directories(tomengine PUBLIC
    "${CMAKE_SOURCE_DIR}/include"
    "${EXTERNAL_DIRECTORY}/include"
    "${EXTERNAL_DIRECTORY}/glad/include"
    "${EXTERNAL_DIRECTORY}/glm-0.9.9.3/include"
)

add_subdirectory("${EXTERNAL_DIRECTORY}/glfw-3.2.1")
add_subdirectory("${CMAKE_SOURCE_DIR}/application")

target_link_libraries(tomengine
    glfw
)