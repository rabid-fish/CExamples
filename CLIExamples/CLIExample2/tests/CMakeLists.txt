# Written with help from http://isti.bitbucket.org/2012/06/01/cmake-check.html
enable_testing()
find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})

set(LIBS ${LIBS} ${CHECK_LIBRARIES})
include_directories(${time_management_SOURCE_DIR}/lib ${time_management_SOURCE_DIR}/tests)

add_executable(check_tm check_time_management_lib.c)
target_link_libraries(check_tm tm ${LIBS})

add_test(check_tm ${CMAKE_CURRENT_BINARY_DIR}/check_tm)

