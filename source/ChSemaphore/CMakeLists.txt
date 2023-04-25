# Add the ChSemaphore library target
add_library(ChSemaphore STATIC
  ChSemaphore.cpp
)

# Set include directories for the library
target_include_directories(ChSemaphore PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChSemaphore PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)