# Add the ChList library target
add_library(ChList STATIC
  ChList.cpp
)

# Set include directories for the library
target_include_directories(ChList PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChList PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)