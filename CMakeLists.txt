cmake_minimum_required(VERSION 3.0)
project(minesweeper)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(EXTERNAL_DIRECTORY "${CMAKE_SOURCE_DIR}/external")

# GLFW build settings
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("${EXTERNAL_DIRECTORY}/glfw-3.2.1")

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable(minesweeper
    ${SOURCES}
    ${EXTERNAL_DIRECTORY}/glad/src/glad.c
)

target_include_directories(minesweeper PUBLIC
    "${CMAKE_SOURCE_DIR}/include"
    "${EXTERNAL_DIRECTORY}/include"
    "${EXTERNAL_DIRECTORY}/glad/include"
    "${EXTERNAL_DIRECTORY}/glm-0.9.9.3/include"
)

target_link_libraries(minesweeper
    glfw
    GL
    X11
    pthread
    Xrandr
    Xi
    dl
)

set(DATA_SRC "${CMAKE_SOURCE_DIR}/data")
set(DATA_DST "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data")
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${DATA_SRC} ${DATA_DST}
    DEPENDS ${DATA_DST}
)
