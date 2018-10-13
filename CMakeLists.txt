cmake_minimum_required(VERSION 2.6)

project(leetcode CXX)

set(CXX_FLAGS
	-g
	)

set(CMAKE_CXX_COMPILER "g++")

string(REPLACE ":" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(200_number-of-islands_BFS 200_number-of-islands_BFS.cpp)
add_executable(200_number-of-islands_DFS 200_number-of-islands_DFS.cpp)
