cmake_minimum_required (VERSION 3.8.2)
project (elf-grapher)

set (CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable (elf-grapher
    main.cpp
    FileDescriptor.cpp
    Graph.cpp
)
add_subdirectory (elf)

target_link_libraries (elf-grapher elf elf-wrappers)
