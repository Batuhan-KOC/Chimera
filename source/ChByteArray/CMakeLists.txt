# Add the ChByteArray library target
add_library(ChByteArray STATIC
  ChByteArray.cpp
)

# Set include directories for the library
target_include_directories(ChByteArray PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChByteArray PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)