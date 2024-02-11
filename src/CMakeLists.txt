cmake_minimum_required(VERSION 3.10.2)

project(SmartCalc)
include(FetchContent)
FetchContent_Declare(
    googletest

    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0 -std=c++17 -Wall -Werror -Wextra")

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(
    model
    model.cpp
    model.h
)

add_executable(
    model_tests
    tests/model_tests.cpp
    tests/tests.h
)

target_link_libraries(
    model_tests
    model
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(model_tests)