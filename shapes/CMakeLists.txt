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

# Add include directories
include_directories( include src )

# Collect .cpp and .h sources from the include directories
file( GLOB files_cpp "src/*.cpp" "src/*.cxx" )
file( GLOB files_h "include/*.h" )

# Add an executable
add_executable( shapes main.cpp ${files_cpp} ${files_h} )

# Link serialization library
target_link_libraries (shapes serialization)
