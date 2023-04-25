# Add the ChTuple library target
add_library(ChTuple STATIC
  ChTuple.cpp
)

# Set include directories for the library
target_include_directories(ChTuple PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChTuple PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)