cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(COSIG)

file(COPY scene.txt DESTINATION  src)
file(COPY evaluation.txt DESTINATION  src)

add_subdirectory(src)
