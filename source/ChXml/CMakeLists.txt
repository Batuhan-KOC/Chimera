# Add the ChXml library target
add_library(ChXml STATIC
  ChXml.cpp
)

# Set include directories for the library
target_include_directories(ChXml PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set the output directory of the library
set_target_properties(ChXml PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib
)