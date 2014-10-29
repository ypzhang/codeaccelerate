cmake_minimum_required(VERSION 2.8.10)

project(snippet)
# ============================================
# === Target
# ============================================
include_directories(./)

file(GLOB_RECURSE my_SRCS "example.cpp")
#file(GLOB_RECURSE my_HEADER "*.h")

set(LIB_NAME "main")
add_executable(${LIB_NAME}
  ${my_SRCS}
  ${my_HEADER}
)

#INSTALL(FILES ${PUBLIC_HEADERS} DESTINATION include)
#INSTALL(FILES "${CMAKE_BINARY_DIR}/src/lib${LIB_NAME}.a" DESTINATION lib)
