include_directories(../lib)
include_directories(../src)

add_executable(tests counting_sort.cpp distance.cpp main.cpp point.cpp)
target_link_libraries(tests algorithms)
