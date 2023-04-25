# Add the ChPriorityQueue library target
add_library(ChPriorityQueue STATIC
  ChPriorityQueue.cpp
)

# Set include directories for the library
target_include_directories(ChPriorityQueue PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChPriorityQueue PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)