# Add the ChObject library target
add_library(ChObject STATIC
  ChObject.cpp
)

# Set include directories for the library
target_include_directories(ChObject PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChObject PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)