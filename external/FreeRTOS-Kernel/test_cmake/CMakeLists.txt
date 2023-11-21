cmake_minimum_required(VERSION 3.14)

project(cmake_build)

add_subdirectory(../ freertos)
unspun_add_freertos(freertos_target ${CMAKE_CURRENT_SOURCE_DIR})