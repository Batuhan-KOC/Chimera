# Add the ChTimer library target
add_library(ChTimer STATIC
  ChTimer.cpp
)

# Set include directories for the library
target_include_directories(ChTimer PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChTimer PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)