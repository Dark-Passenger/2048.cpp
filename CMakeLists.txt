cmake_minimum_required(VERSION 3.8)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" FALSE)

# Link this 'library' to use the following warnings
add_library(project_warnings INTERFACE)

if(MSVC)
  target_compile_options(project_warnings INTERFACE /W4)
else()
  target_compile_options(project_warnings
                         INTERFACE
                         -Wall
                         -Wextra # reasonable and standard
                         -Wshadow # warn the user if a variable declaration shadows one from a
                                  # parent context
                         -Wpedantic # warn if non-standard C++ is used
                         )
endif()

add_executable(2048 main.cpp)
set (CMAKE_CXX_STANDARD 11)
target_link_libraries(2048 PRIVATE project_warnings)
