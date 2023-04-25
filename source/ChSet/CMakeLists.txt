# Add the ChSet library target
add_library(ChSet STATIC
  ChSet.cpp
)

# Set include directories for the library
target_include_directories(ChSet PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChSet PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)