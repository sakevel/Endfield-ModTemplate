cmake_minimum_required(VERSION 3.25)
project(EndfieldSampleMod VERSION 0.1.0 LANGUAGES CXX)

if(NOT WIN32 OR NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
  message(FATAL_ERROR "Windows x64 required")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
add_compile_options(/utf-8 /W4 /permissive-)
add_compile_definitions(UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX)

add_library(SampleMod SHARED src/plugin.cpp)
target_include_directories(SampleMod PRIVATE src sdk/include)
set_target_properties(SampleMod PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/package/$<CONFIG>/sample-mod")

add_custom_target(package ALL DEPENDS SampleMod)
foreach(file mod.ini config.ini icon.png sample-mod.lua zml-package.json)
  add_custom_command(TARGET package POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
    "${CMAKE_CURRENT_SOURCE_DIR}/mod/${file}" "${CMAKE_BINARY_DIR}/package/$<CONFIG>/sample-mod/${file}")
endforeach()
