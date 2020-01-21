cmake_minimum_required(VERSION 3.15)
project(dictionaryClass)

set(CMAKE_CXX_STANDARD 14)

add_executable(dictionaryClass main.cpp Dictionary.cpp Dictionary.h LinkedList.h)