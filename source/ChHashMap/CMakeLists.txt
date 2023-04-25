# Add the ChHashMap library target
add_library(ChHashMap STATIC
  ChHashMap.cpp
)

# Set include directories for the library
target_include_directories(ChHashMap PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChHashMap PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)