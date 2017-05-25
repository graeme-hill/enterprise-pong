cmake_minimum_required(VERSION 3.5.1)
project(pong)

include_directories(modules)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Require GLM
find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIR})
if(NOT GLM_FOUND)
    message(ERROR " GLM not found!")
endif(NOT GLM_FOUND)

add_subdirectory(modules/xe)

set(SOURCES Main.cpp Pong.cpp Paddle.cpp)
add_executable(pong ${SOURCES})
target_link_libraries(pong xe)

# copy assets to bin dir
configure_file(assets/vert.glsl assets/vert.glsl COPYONLY)
configure_file(assets/frag.glsl assets/frag.glsl COPYONLY)

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
