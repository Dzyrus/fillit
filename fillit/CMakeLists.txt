cmake_minimum_required(VERSION 3.14)
project(fillit C)

set(CMAKE_C_STANDARD 99)


add_executable(fillit main.c fillit.h validator.c spliter.c solver.c)
target_link_libraries (fillit ${CMAKE_SOURCE_DIR}/libft/libft.a)