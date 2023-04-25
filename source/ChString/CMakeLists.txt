# Add the ChString library target
add_library(ChString STATIC
  ChString.cpp
)

# Set include directories for the library
target_include_directories(ChString PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChString PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)