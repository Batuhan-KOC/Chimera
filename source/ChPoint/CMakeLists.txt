# Add the ChPoint library target
add_library(ChPoint STATIC
  ChPoint.cpp
)

# Set include directories for the library
target_include_directories(ChPoint PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChPoint PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)