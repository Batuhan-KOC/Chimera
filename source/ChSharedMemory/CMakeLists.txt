# Add the ChSharedMemory library target
add_library(ChSharedMemory STATIC
  ChSharedMemory.cpp
)

# Set include directories for the library
target_include_directories(ChSharedMemory PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChSharedMemory PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)