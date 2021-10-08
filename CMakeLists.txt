cmake_minimum_required(VERSION 3.20)
project(Benchme C)

set(CMAKE_C_STANDARD 99)

add_executable(Benchme main.c libs/generateArray.c libs/header.h libs/InsertionSort.c libs/HeapSort.c libs/bubbleSort.c libs/selectionSort.c)