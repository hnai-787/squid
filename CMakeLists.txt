cmake_minimum_required(VERSION 3.20)
project(bracketsched CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(nlohmann_json CONFIG REQUIRED)

add_library(bracketsched_core
    src/types.cpp
    src/seeding.cpp
    src/generator.cpp
    src/serialize.cpp
)
target_include_directories(bracketsched_core PUBLIC include)
target_link_libraries(bracketsched_core PUBLIC nlohmann_json::nlohmann_json)
if(MINGW)
    target_link_options(bracketsched_core PUBLIC -static)
endif()

# The shared library exposing the C ABI (see capi/bracketsched_capi.h).
add_library(bracketsched_capi SHARED src/capi.cpp)
target_include_directories(bracketsched_capi PUBLIC capi)
target_link_libraries(bracketsched_capi PRIVATE bracketsched_core)
target_compile_definitions(bracketsched_capi PRIVATE BRACKETSCHED_EXPORTS)

add_executable(bracket src/main.cpp)
target_link_libraries(bracket PRIVATE bracketsched_core)

option(BRACKETSCHED_BUILD_TESTS "Build the bracketsched unit test suite" ON)
if(BRACKETSCHED_BUILD_TESTS)
    find_package(Catch2 3 CONFIG REQUIRED)
    add_executable(bracketsched_tests
        tests/test_seeding.cpp
        tests/test_single_elimination.cpp
        tests/test_double_elimination.cpp
        tests/test_serialize.cpp
    )
    target_link_libraries(bracketsched_tests PRIVATE bracketsched_core Catch2::Catch2WithMain)

    enable_testing()
    include(CTest)
    add_test(NAME bracketsched_tests COMMAND bracketsched_tests)
endif()
