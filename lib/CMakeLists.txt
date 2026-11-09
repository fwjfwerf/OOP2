add_library(time_counters STATIC
    src/TimeCounter.cpp
    src/Timer.cpp
    src/Stopwatch.cpp
)

target_include_directories(time_counters PUBLIC include)
target_compile_features(time_counters PUBLIC cxx_std_17)
