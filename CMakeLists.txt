cmake_minimum_required(VERSION 3.5.1)
project(pong)

include_directories(modules)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(modules/cg)
add_subdirectory(modules/cr)

set(SOURCES Main.cpp Pong.cpp)
add_executable(pong ${SOURCES})
target_link_libraries(pong cg)
target_link_libraries(pong cr)

# Enable warnings
if(MSVC)
	# Force to always compile with W4
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
	# Update if necessary
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()