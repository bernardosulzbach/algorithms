include_directories(../src)

add_executable(counting_sort counting_sort.cpp)
target_link_libraries(counting_sort algorithms)