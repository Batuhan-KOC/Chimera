# Add the ChMap library target
add_library(ChMap STATIC
  ChMap.cpp
)

# Set include directories for the library
target_include_directories(ChMap PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChMap PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)