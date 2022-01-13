# 1. Indicate the required version of CMake (we want version 3.0) :
CMAKE_MINIMUM_REQUIRED( VERSION 3.0 )

# 2. Indicate the name of the project :
project( TPBatailleNavale )

# Binaries will be saved there
# ${PROJECT_SOURCE_DIR} is a variable, it is the top level source directory for the current project.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

# Locate Threads
# needed for Google Test
find_package(Threads REQUIRED)
find_package(GLUT REQUIRED)

# Main project entry point
file(GLOB_RECURSE SRC_MAIN "src/main.cpp")

# Main project sources without main
file(GLOB_RECURSE SRC_FILES "src/**.cpp")
list(REMOVE_ITEM SRC_FILES "src/main.cpp")

# Tests sources
file(GLOB GTESTS "tests/**.cpp")

# Allow include to use paths relative to project root
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${GLUT_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/googletest/googletest/include) # add the include directory of google test



# create target
# 3. Uncomment these two next lines and complete them.
# The first executable is for running the tests, add all needed files for the tests.
# The second executable is for running the main code, add all needed files for the code to compile.
# Note : you can write all files by hand or use file(GLOB...) or file(GLOB_RECURSE...)

add_executable ( run_tests tests/gtests.cpp src/lib.cpp )
add_executable ( TPBatailleNavale ${SRC_MAIN}  ${SRC_FILES} )


# link run_tests to gtest and pthread
target_link_libraries(run_tests ${CMAKE_SOURCE_DIR}/build_gtest/lib/libgtest.a pthread)
target_link_libraries(TPBatailleNavale ${GLUT_LIBRARIES})
