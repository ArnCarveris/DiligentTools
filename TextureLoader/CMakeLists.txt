cmake_minimum_required (VERSION 3.3)

project(TextureLoader)

set(INCLUDE 
	include/DDSLoader.h
	include/dxgiformat.h
	include/pch.h
)

set(INTERFACE
	interface/Image.h
	interface/TextureLoader.h
	interface/TextureUtilities.h
)

set(SOURCE 
	src/DDSLoader.cpp
	src/Image.cpp
	src/pch.cpp
	src/TextureLoader.cpp
	src/TextureUtilities.cpp
)

add_library(TextureLoader STATIC ${SOURCE} ${INCLUDE})

target_include_directories(TextureLoader
PUBLIC
	include
	interface
)

source_group("source" FILES ${SOURCE})
source_group("include" FILES ${INCLUDE})

target_link_libraries(TextureLoader PRIVATE BuildSettings Common PlatformInterface GraphicsEngine GraphicsTools LibJpeg LibPng LibTiff Lua ZLib)