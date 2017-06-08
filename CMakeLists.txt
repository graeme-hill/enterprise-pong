cmake_minimum_required(VERSION 3.5.1)
project(pong)

option(JS "JS" OFF)

if(JS)
	set(OUTFILE "pong.html")
else()
	set(OUTFILE "pong")
endif()

include_directories(modules)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(modules/xe)

set(SOURCES
	Main.cpp
	Pong.cpp
	Paddle.cpp
	Court.cpp
	Ball.cpp
	MovementSystem.cpp)
add_executable(${OUTFILE} ${SOURCES})
target_link_libraries(${OUTFILE} xe)

if (JS)
	target_link_libraries(${OUTFILE} "--embed-file assets")
else()
	add_subdirectory(modules/xs)
	target_link_libraries(${OUTFILE} xs)
endif()

target_compile_definitions(xe PUBLIC GLM_FORCE_PURE)

# copy assets to bin dir
configure_file(assets/standard-vert.glsl assets/standard-vert.glsl COPYONLY)
configure_file(assets/standard-frag.glsl assets/standard-frag.glsl COPYONLY)
configure_file(assets/court-vert.glsl assets/court-vert.glsl COPYONLY)
configure_file(assets/court-frag.glsl assets/court-frag.glsl COPYONLY)
configure_file(assets/paddle.obj assets/paddle.obj COPYONLY)
configure_file(assets/court.obj assets/court.obj COPYONLY)
configure_file(assets/ball.obj assets/ball.obj COPYONLY)

# Enable warnings
if(MSVC)
	# Force to always compile with W4
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
else()
	# Update if necessary
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()
