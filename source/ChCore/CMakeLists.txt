# Add the ChCore library target
add_library(ChCore STATIC
  ChCore.cpp
)

# Set include directories for the library
target_include_directories(ChCore PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChCore PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)