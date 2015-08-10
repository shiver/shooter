cmake_minimum_required(VERSION 2.8)
project(shooter)

add_subdirectory(libs/SDL2-2.0.3)
include_directories(${SDL2_SOURCE_DIR}/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++14")

add_executable(shooter src/main.cpp)

target_link_libraries(shooter SDL2main SDL2-static)
install(TARGETS shooter RUNTIME DESTINATION bin/)
