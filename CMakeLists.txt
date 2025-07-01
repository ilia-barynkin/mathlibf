cmake_minimum_required(VERSION 3.10)
project(mathlibf C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

#TODO: get rid of stdlib
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffresstanding -fno-builtin -nostdlib -Wall -Wextra Werror")

enable_testing()

add_subdirectory(core)
add_subdirectory(geometry)
#add_subdirectory(filter)
#add_subdirectory(matrix)