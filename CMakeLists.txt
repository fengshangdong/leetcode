cmake_minimum_required(VERSION 2.6)

project(leetcode CXX)

set(CXX_FLAGS
	-g
	)

set(CMAKE_CXX_COMPILER "g++")

string(REPLACE ":" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
 
add_executable(021_merge-two-sorted-lists				021_merge-two-sorted-lists.cpp)
add_executable(023_merge-k-sorted-lists					023_merge-k-sorted-lists.cpp)
add_executable(053_maximum-subarray_DP					053_maximum-subarray_DP.cpp)
add_executable(064_minimum-path-sum_DP					064_minimum-path-sum_DP.cpp)
add_executable(070_climbing-stairs_DP					070_climbing-stairs_DP.cpp)
add_executable(086_partition-list						086_partition-list.cpp)
add_executable(092_reverse-linked-list-ii				092_reverse-linked-list-ii.cpp)
add_executable(120_triangle_DP							120_triangle_DP.cpp)
add_executable(126_word-ladder-ii_BFS					126_word-ladder-ii_BFS.cpp)
add_executable(127_word-ladder_BFS						127_word-ladder_BFS.cpp)
add_executable(141_linked-list-cycle					141_linked-list-cycle.cpp)
add_executable(142_linked-list-cycle-ii					142_linked-list-cycle-ii.cpp)
add_executable(160_intersection-of-two-linked-lists		160_intersection-of-two-linked-lists.cpp)
add_executable(198_house-robber_DP						198_house-robber_DP.cpp)
add_executable(200_number-of-islands_BFS				200_number-of-islands_BFS.cpp)
add_executable(200_number-of-islands_DFS				200_number-of-islands_DFS.cpp)
add_executable(206_reverse-linked-list_ITER				206_reverse-linked-list_ITER.cpp)
add_executable(206_reverse-linked-list_REC				206_reverse-linked-list_REC.cpp)
add_executable(225_implement-stack-using-queues			225_implement-stack-using-queues.cpp)
add_executable(232_implement-queue-using-stacks			232_implement-queue-using-stacks.cpp)
add_executable(300_longest-increasing-subsequence_DP	300_longest-increasing-subsequence_DP.cpp)
add_executable(300_longest-increasing-subsequence_STACK 300_longest-increasing-subsequence_STACK.cpp)
add_executable(322_coin-change_DP						322_coin-change_DP.cpp)
add_executable(473_matchsticks-to-square_DFS			473_matchsticks-to-square_DFS.cpp)
add_executable(473_matchsticks-to-square_BitMap			473_matchsticks-to-square_BitMap.cpp)
