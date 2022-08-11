cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi")

add_subdirectory(Triangle)

add_executable(Main main.cpp)

target_link_libraries(Main PUBLIC Triangle)

target_include_directories(Main PUBLIC
                            "${PROJECT_BINARY_DIR}",
                            "${PROJECT_SOURCE_DIR}/triangle")