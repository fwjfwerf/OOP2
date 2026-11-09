cmake_minimum_required(VERSION 3.16)

project(TimerProject LANGUAGES CXX)

add_subdirectory(lib)

find_package(Threads REQUIRED)

add_executable(timer_demo src/main.cpp)
target_link_libraries(timer_demo PRIVATE time_counters Threads::Threads)
