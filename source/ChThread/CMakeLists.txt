# Add the ChThread library target
add_library(ChThread STATIC
  ChThread.cpp
)

# Set include directories for the library
target_include_directories(ChThread PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChThread PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)