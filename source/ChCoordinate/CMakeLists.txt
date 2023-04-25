# Add the ChCoordinate library target
add_library(ChCoordinate STATIC
  ChCoordinate.cpp
)

# Set include directories for the library
target_include_directories(ChCoordinate PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChCoordinate PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)