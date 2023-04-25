# Add the ChQueue library target
add_library(ChQueue STATIC
  ChQueue.cpp
)

# Set include directories for the library
target_include_directories(ChQueue PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChQueue PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)