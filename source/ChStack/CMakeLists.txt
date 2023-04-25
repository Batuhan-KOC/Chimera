# Add the ChStack library target
add_library(ChStack STATIC
  ChStack.cpp
)

# Set include directories for the library
target_include_directories(ChStack PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChStack PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)