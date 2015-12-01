include_directories(../lib)
include_directories(../src)

add_executable(tests distance.cpp main.cpp point.cpp)
target_link_libraries(tests algorithms)
