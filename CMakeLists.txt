cmake_minimum_required(VERSION 2.8)
project(shooter)

set(glew-cmake_BUILD_STATIC OFF CACHE BOOL "Disable static library" FORCE)
set(SDL_STATIC OFF CACHE BOOL "Disable static library" FORCE)

add_subdirectory(libs/SDL2)
include_directories(${SDL2_SOURCE_DIR}/include)

add_subdirectory(libs/glew)
SET(GLEW_SOURCE_DIR libs/glew)
include_directories(${GLEW_SOURCE_DIR}/include)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    include_directories($ENV{DXSDK_DIR}/Include)
    link_directories("$ENV{DXSDK_DIR}/Lib/x86")
    ADD_DEFINITIONS(/arch:SSE)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++14")
endif()

file(GLOB shooter_SRC
    "src/*.h"
    "src/*.cpp"
)

add_custom_command(TARGET shooter POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/libs/"
)

add_executable(shooter ${shooter_SRC})

target_link_libraries(shooter SDL2main SDL2 libglew_shared)
install(TARGETS shooter RUNTIME DESTINATION bin/)
