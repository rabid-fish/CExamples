cmake_minimum_required (VERSION 2.8)
project (time_management)

# Cause CMake to see our custom glib .cmake file
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/build/")

# Cause CMake to add debug symbols to compiled output
set(CMAKE_BUILD_TYPE Debug)

find_package(GLIB2 REQUIRED)
include_directories(${GLIB2_INCLUDE_DIRS})
set(LIBS ${LIBS} ${GLIB2_LIBRARIES})

enable_testing()

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)

