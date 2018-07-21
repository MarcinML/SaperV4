cmake_minimum_required(VERSION 2.8)

project(Saper)


FILE(GLOB TARGET_SRC  ./src/*.cpp)
FILE(GLOB TARGET_INC ./inc/*.h)
FILE(GLOB TARGET_GTEST ./tests/*.cpp)


add_executable(${PROJECT_NAME} ./main.cpp ${TARGET_SRC} ${TARGET_INC})
INCLUDE_DIRECTORIES(./inc)

# TESTS
set(GTEST_LIBRARY "$ENV{GTEST_LIBRARY}")
set(GTEST_INCLUDE_DIR "$ENV{GTEST_INCLUDE_DIR}")
set(GTEST_MAIN_LIBRARY "$ENV{GTEST_MAIN_LIBRARY}")
enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(runUnitTests ${TARGET_GTEST} ${TARGET_SRC})

target_link_libraries(runUnitTests ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})

