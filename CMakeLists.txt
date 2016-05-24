cmake_minimum_required(VERSION 2.8.11)
project(Shapes)

#Preprocessor definitions
if (WIN32)
	add_definitions(-DCL_COMP)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /EHsc")
	# Activate use of multi-processor compilation if we have Microsft Visual C++ compiler.
	if (MSVC)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
	endif (MSVC)
endif (WIN32)

# GUI Type
if(WIN32)
	set(gui_type WIN32)
endif(WIN32)
if(APPLE)
	set(gui_type MACOSX_BUNDLE)
endif(APPLE)

# Collect .cpp and .h sources from the  module directory
include_directories( src )
file( GLOB files_cpp "src/*.cpp" "src/*.cxx" )
file( GLOB files_h "src/*.h" )

#Add an executable
add_executable( Shapes ${files_cpp} ${files_h} )