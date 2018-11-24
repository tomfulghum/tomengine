project(minesweeper)

set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/minesweeper")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(minesweeper
    ${SOURCES}
)

#target_include_directories(minesweeper PUBLIC
#    "${CMAKE_SOURCE_DIR}/include"
#)

target_link_libraries(minesweeper tomengine)

set(DATA_SRC "${CMAKE_CURRENT_SOURCE_DIR}/data")
set(DATA_DST "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data")
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${DATA_SRC} ${DATA_DST}
    DEPENDS ${DATA_DST}
)
