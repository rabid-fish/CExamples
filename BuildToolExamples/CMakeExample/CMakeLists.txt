cmake_minimum_required (VERSION 2.8)
project (time_management)
add_executable (time_management main.c)

# Cause CMake to see our custom glib .cmake file
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/build/")

find_package(GLIB2 REQUIRED)
include_directories(${GLIB2_INCLUDE_DIRS})
set(LIBS ${LIBS} ${GLIB2_LIBRARIES})
target_link_libraries(time_management ${LIBS})

