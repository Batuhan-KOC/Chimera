# Add the ChUnorderedSet library target
add_library(ChUnorderedSet STATIC
  ChUnorderedSet.cpp
)

# Set include directories for the library
target_include_directories(ChUnorderedSet PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChUnorderedSet PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)