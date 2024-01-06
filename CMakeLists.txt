cmake_minimum_required(VERSION 3.2)
include(FindPkgConfig)

project("SyobonActionRaylib" LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall -Wpedantic")
set(SRC_DIR "src")

file(GLOB_RECURSE SRC_FILES
    "${SRC_DIR}/*.c"
    "${SRC_DIR}/*.h"
)
set(SOURCES "${SRC_FILES}")

pkg_search_module(RAYLIB REQUIRED raylib)
include_directories("${RAYLIB_INCLUDE_DIRS}")

add_executable("${PROJECT_NAME}" "${SOURCES}")
target_link_libraries("${PROJECT_NAME}" "${RAYLIB_LIBRARIES}")