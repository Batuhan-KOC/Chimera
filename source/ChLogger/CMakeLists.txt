# Add the ChLogger library target
add_library(ChLogger STATIC
  ChLogger.cpp
)

# Set include directories for the library
target_include_directories(ChLogger PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChLogger PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)