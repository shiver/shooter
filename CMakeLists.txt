cmake_minimum_required(VERSION 2.8)
project(shooter)

set(glew-cmake_BUILD_STATIC OFF CACHE BOOL "Disable static library" FORCE)
set(SDL_STATIC OFF CACHE BOOL "Disable static library" FORCE)

add_subdirectory(libs/SDL2-2.0.3)
include_directories(${SDL2_SOURCE_DIR}/include)

add_subdirectory(libs/glew-cmake-1.13.0/)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++14")
endif()

add_executable(shooter src/main.cpp)

target_link_libraries(shooter SDL2main SDL2 libglew_shared)
install(TARGETS shooter RUNTIME DESTINATION bin/)
