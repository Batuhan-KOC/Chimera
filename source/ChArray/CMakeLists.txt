# Add the ChArray library target
add_library(ChArray STATIC
  ChArray.cpp
)

# Set include directories for the library
target_include_directories(ChArray PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChArray PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)