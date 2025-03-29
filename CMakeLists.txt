# CMakeList.txt : CMake project for Potentials, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Potentials")

# Add source to this project's executable.
add_executable (Potentials "src/Potentials.cpp" "src/GaussianElement.cpp")





if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Potentials PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/52204f78f94d7512df1f0f3bea1d47437a2c3a58.zip)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(AllTests "tests/test_GaussianElement.cpp" "src/GaussianElement.cpp")
target_link_libraries(AllTests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(AllTests)

add_test(NAME MyTests COMMAND AllTests)