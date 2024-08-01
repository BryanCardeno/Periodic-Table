cmake_minimum_required(VERSION 3.27)
project(Final_Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Final_Project main.cpp
               Element/Element.cpp
               Element/Element.h
               ElementLookup/ElementLookup.cpp
               ElementLookup/ElementLookup.h
               "AVL Tree/AvlTree.h"
               ElementLookupException/ElementLookupException.h
               ElementLookupException/ElementLookupException.cpp)
