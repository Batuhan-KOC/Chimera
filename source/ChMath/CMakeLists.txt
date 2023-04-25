# Add the ChMath library target
add_library(ChMath STATIC
  ChMath.cpp
)

# Set include directories for the library
target_include_directories(ChMath PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChMath PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)