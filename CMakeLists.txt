cmake_minimum_required(VERSION 3.19)
project(BST)

set(CMAKE_CXX_STANDARD 14)


add_executable(shunxubiao shunxubiao.cpp)
add_executable(danlianbiao danlianbiao.cpp)
add_executable(Stack Stack.cpp)
add_executable(Queue Queue.cpp)
add_executable(LinkQueue LinkQueue.cpp)
add_executable(test test.cpp)

add_executable(ThreadBinaryTree ThreadBinaryTree.cpp)
add_executable(zhongxuxiansuoerchashu zhongxuxiansuoerchashu.c)