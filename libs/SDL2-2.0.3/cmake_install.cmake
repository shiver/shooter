# Install script for directory: E:/src/shooter/libs/SDL2-2.0.3

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Project")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/Debug/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/Release/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/MinSizeRel/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/RelWithDebInfo/SDL2.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/src/shooter/libs/SDL2-2.0.3/Debug/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/src/shooter/libs/SDL2-2.0.3/Release/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/src/shooter/libs/SDL2-2.0.3/MinSizeRel/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/src/shooter/libs/SDL2-2.0.3/RelWithDebInfo/SDL2.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/Debug/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/Release/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/MinSizeRel/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/RelWithDebInfo/SDL2main.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "E:/src/shooter/libs/SDL2-2.0.3/include/begin_code.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/close_code.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_assert.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_atomic.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_audio.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_bits.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_blendmode.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_clipboard.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config_android.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config_iphoneos.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config_macosx.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config_minimal.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config_pandora.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config_psp.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config_windows.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config_winrt.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_config_wiz.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_copying.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_cpuinfo.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_egl.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_endian.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_error.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_events.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_filesystem.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_gamecontroller.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_gesture.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_haptic.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_hints.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_joystick.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_keyboard.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_keycode.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_loadso.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_log.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_main.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_messagebox.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_mouse.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_mutex.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_name.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_opengl.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_opengles.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_opengles2.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_pixels.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_platform.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_power.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_quit.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_rect.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_render.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_revision.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_rwops.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_scancode.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_shape.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_stdinc.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_surface.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_system.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_syswm.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_assert.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_common.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_compare.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_crc32.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_font.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_fuzzer.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_harness.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_images.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_log.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_md5.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_test_random.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_thread.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_timer.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_touch.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_types.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_version.h"
    "E:/src/shooter/libs/SDL2-2.0.3/include/SDL_video.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/Debug/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/Release/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/MinSizeRel/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/src/shooter/libs/SDL2-2.0.3/RelWithDebInfo/SDL2.dll")
  endif()
endif()

