cmake_minimum_required(VERSION 3.5.1)
project(pong)

option(JS "JS" OFF)

if(JS)
	set(OUTFILE "pong.html")
else()
	set(OUTFILE "pong")
endif()

set(GEN_DIR ${CMAKE_SOURCE_DIR}/generated)
set(FBS_EXE ${CMAKE_BINARY_DIR}/xe/modules/flatbuffers/flatc)

# Make sure the generated/ folder exists
# add_custom_command(
# 	COMMAND mkdir -p ${GEN_DIR}
# 	OUTPUT ${GEN_DIR}
# 	COMMENT "Creating generated/ folder")

# Auto-generate flatbuffers classes
include_directories(xe/modules/flatbuffers/include)
if(NOT JS)
	add_custom_command(
		COMMAND ${FBS_EXE} --cpp -o ${GEN_DIR} ${CMAKE_SOURCE_DIR}/GameMessage.fbs
		DEPENDS ${FBS_EXE} ${CMAKE_SOURCE_DIR}/GameMessage.fbs # generated ${FBS_EXE}
		OUTPUT ${GEN_DIR}/GameMessage_generated.h
		COMMENT "Generate flatbuffers")
	add_custom_target(codegen ALL DEPENDS ${GEN_DIR}/GameMessage_generated.h)
	add_dependencies(codegen flatc)
	target_compile_definitions(xe PUBLIC FEATURE_SERVER)
endif()

include_directories(
	xe
	xe/modules
	xe/modules/websocketpp
	xe/modules/flatbuffers/include
	xe/modules/asio/asio/include)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(xe)

set(SOURCES
	Main.cpp
	Pong.cpp
	Paddle.cpp
	Court.cpp
	Ball.cpp
	MovementSystem.cpp
	PlayPong.cpp
	MenuPong.cpp
	PongServer.cpp)
#	generated/GameMessage.c++)
add_executable(${OUTFILE} ${SOURCES})
target_link_libraries(${OUTFILE} xe)

if (JS)
	target_link_libraries(${OUTFILE} "--embed-file assets")
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
