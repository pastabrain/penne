cmake_minimum_required(VERSION 3.0)
project(penne)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(CURSES REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs)

add_library(penne SHARED src/canvas.c src/element.c src/elements/string.c)

target_link_libraries(penne ${CURSES_LIBRARY})
