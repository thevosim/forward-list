cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME forward_list)
project(${PROJECT_NAME})

include(CTest)

set(TESTS   "test_${PROJECT_NAME}")
set(CUSTOM_PROJECT "${PROJECT_NAME}")
set(INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory(include)
add_subdirectory(gtest)
add_subdirectory(test)

# REPORT
message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")
