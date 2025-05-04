cmake_minimum_required(VERSION 3.14)

project(Potentials LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Hot Reload for MSVC compilers if supported
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Main executable
add_executable(Potentials
        src/Potentials.cpp
        src/GaussianElement.cpp
        src/Potential.cpp
        src/ElementPot.cpp
        src/Particle.cpp
        src/EnsembleOfParticles.cpp
        src/EnsembleOfParticles.h
)

# ----------- GoogleTest via FetchContent (portable, no install needed) -----------
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# For Windows: avoid overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Tests executable
add_executable(AllTests
        tests/test_GaussianElement.cpp
        tests/test_Potential.cpp
        tests/test_Particle.cpp
        tests/test_EnsembleOfParticles.cpp
        src/GaussianElement.cpp
        src/Potential.cpp
        src/ElementPot.cpp
        src/Particle.cpp
        src/EnsembleOfParticles.cpp
        src/EnsembleOfParticles.h
        tests/test_DummyPotentialElement.h
)

# Link GoogleTest
target_link_libraries(AllTests PRIVATE GTest::gtest_main)

# Discover and register tests
include(GoogleTest)
gtest_discover_tests(AllTests)

add_test(NAME MyTests COMMAND AllTests)
