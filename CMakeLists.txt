cmake_minimum_required(VERSION 3.21)
project(dsa_l1)

set(CMAKE_CXX_STANDARD 20)

add_executable(dsa_l1 App.cpp Bag.cpp Bag.h BagIterator.cpp BagIterator.h ExtendedTest.cpp ExtendedTest.h ShortTest.cpp ShortTest.h RAIterator.cpp RAIterator.h)
