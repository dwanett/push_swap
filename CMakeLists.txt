cmake_minimum_required(VERSION 3.10)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap push_swap.c utils.c create_and_check_stack.c push.c swap.c rotate.c reverse_rotate.c)
target_link_libraries(push_swap /Users/dwanetta/Desktop/push_swap/libft/libft.a)