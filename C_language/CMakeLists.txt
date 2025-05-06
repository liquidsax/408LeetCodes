cmake_minimum_required(VERSION 3.26)
project(C_language C)

set(CMAKE_C_STANDARD 11)

add_executable(C_language
        QueueInStack.c
        StackUsingQueue.c
        InorderTree.c
        MaxHeightTree.c)
