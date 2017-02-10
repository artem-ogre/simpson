project(serialization)

# Add include directories
include_directories( include include_core include_private src )

# Collect .cpp and .h sources from the include directories
file( GLOB files_cpp "src/*.cpp" "src/*.cxx" )
file( GLOB files_h "include/*.h" "include_core/*.h" "include_private/*.h")

# Add a library
add_library( serialization STATIC ${files_cpp} ${files_h} )

# Specify library's include directory
target_include_directories( serialization PUBLIC include include_core include_private )
