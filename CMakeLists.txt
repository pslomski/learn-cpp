cmake_minimum_required(VERSION 3.22.1)
project(learncpp VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-O0")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-Wextra")
set(CMAKE_CXX_FLAGS "-Werror")
set(CMAKE_CXX_FLAGS "-pedantic")
set(CMAKE_CXX_FLAGS "-m64")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_MODULE_PATH)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
enable_testing()
  
add_executable(learncpp)
add_subdirectory(src)

target_link_libraries(learncpp
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(learncpp)
