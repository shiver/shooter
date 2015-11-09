cmake_minimum_required(VERSION 2.8)
project(shooter)

foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

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

add_subdirectory(libs/glew)
SET(GLEW_SOURCE_DIR libs/glew)
include_directories(${GLEW_SOURCE_DIR}/include)

SET(EASYLOGGINGPP_SOURCE_DIR libs/easyloggingpp)
include_directories(${EASYLOGGINGPP_SOURCE_DIR}/src)

INCLUDE(ExternalProject)
ExternalProject_Add(project_SDL2_image
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/SDL2_image
    PREFIX ${CMAKE_BINARY_DIR}/libs/SDL2_image
    CONFIGURE_COMMAND ${CMAKE_SOURCE_DIR}/libs/SDL2_image/autogen.sh && ${CMAKE_SOURCE_DIR}/libs/SDL2_image/configure --prefix ${CMAKE_BINARY_DIR} --libdir ${CMAKE_BINARY_DIR}/libs/SDL2_image
	BUILD_COMMAND make
    INSTALL_COMMAND make install
)
ExternalProject_Get_Property(project_SDL2_image install_dir)
add_library(SDL2_image STATIC IMPORTED)
set_property(TARGET SDL2_image PROPERTY IMPORTED_LOCATION ${install_dir}/libSDL2_image.a)
add_dependencies(SDL2_image project_SDL2_image)

SET(SDL2_IMAGE_SOURCE_DIR libs/SDL2_image)
include_directories(${SDL2_IMAGE_SOURCE_DIR})

file(GLOB shooter_SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable(shooter ${shooter_SRC})
target_link_libraries(shooter
    optimized SDL2 debug SDL2
    optimized SDL2main debug SDL2main
	optimized SDL2_image debug SDL2_image
    optimized libglew_shared debug libglew_shared)
install(TARGETS shooter DESTINATION bin)
