# Add the ChDeque library target
add_library(ChDeque STATIC
  ChDeque.cpp
)

# Set include directories for the library
target_include_directories(ChDeque PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChDeque PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)