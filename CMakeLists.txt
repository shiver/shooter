cmake_minimum_required(VERSION 2.8)
project(shooter)


set(CMAKE_LIBRARY_OUTPUT_DIR bin/)
if(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    include_directories($ENV{DXSDK_DIR}/Include)
    link_directories("$ENV{DXSDK_DIR}/Lib/x86")
    set(EXTRA_CFLAGS "${EXTRA_CFLAGS} /arch:SSE")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++14")
endif()

set(glew-cmake_BUILD_STATIC OFF CACHE BOOL "Disable static library" FORCE)
set(SDL_STATIC OFF CACHE BOOL "Disable static library" FORCE)

add_subdirectory(libs/SDL2)
include_directories(${SDL2_SOURCE_DIR}/include)

set_target_properties(SDL2 PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG ../../bin/debug
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE ../../bin/release
)

set_target_properties(SDL2main PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG ../../bin/debug
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE ../../bin/release
)

add_subdirectory(libs/glew)
SET(GLEW_SOURCE_DIR libs/glew)
include_directories(${GLEW_SOURCE_DIR}/include)

set_target_properties(libglew_shared PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG ../../bin/debug
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE ../../bin/release
)

SET(EASYLOGGINGPP_SOURCE_DIR libs/easyloggingpp)
include_directories(${EASYLOGGINGPP_SOURCE_DIR}/src)

file(GLOB shooter_SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable(shooter ${shooter_SRC})
target_link_libraries(shooter SDL2main SDL2 libglew_shared)
install(TARGETS shooter RUNTIME DESTINATION bin/)
