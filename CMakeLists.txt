cmake_minimum_required (VERSION 3.0)
project (HexEcho VERSION 1.1)
add_executable (hexecho hexecho.c)
add_executable (hexcat hexcat.c)
add_library (hextools STATIC hextools.c)
target_link_libraries (hexecho hextools)
target_link_libraries (hexcat hextools)

if(NOT INSTALL_DIR)
  set (INSTALL_DIR "${PROJECT_BINARY_DIR}\\bin")
endif()
install (TARGETS hexecho DESTINATION ${INSTALL_DIR})
install (TARGETS hexcat DESTINATION ${INSTALL_DIR})

message("INSTALL_DIR ${INSTALL_DIR}")
message("PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
message("PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})


