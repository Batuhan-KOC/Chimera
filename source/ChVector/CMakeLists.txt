# Add the ChVector library target
add_library(ChVector STATIC
  ChVector.cpp
)

# Set include directories for the library
target_include_directories(ChVector PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChVector PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)