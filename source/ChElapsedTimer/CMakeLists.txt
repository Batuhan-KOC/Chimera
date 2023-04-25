# Add the ChElapsedTimer library target
add_library(ChElapsedTimer STATIC
  ChElapsedTimer.cpp
)

# Set include directories for the library
target_include_directories(ChElapsedTimer PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChElapsedTimer PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)