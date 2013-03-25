include_directories(${time_management_SOURCE_DIR}/lib)
link_directories(${time_management_BINARY_DIR}/lib)
add_executable(time_management main.c)
target_link_libraries(time_management tm ${LIBS})

