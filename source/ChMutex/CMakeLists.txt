# Add the ChMutex library target
add_library(ChMutex STATIC
  ChMutex.cpp
)

# Set include directories for the library
target_include_directories(ChMutex PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChMutex PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)