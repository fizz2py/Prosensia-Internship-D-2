cmake_minimum_required(VERSION 3.10)

project(LinkedListProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    LinkedListProject
    main.cpp
    LinkedList.cpp
    NodeObserver.cpp
)

target_compile_options(LinkedListProject PRIVATE
    -Wall
    -Wextra
    -Werror
    -fsanitize=address
)

target_link_options(LinkedListProject PRIVATE
    -fsanitize=address
)