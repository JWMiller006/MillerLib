# Must be 2.8 for the Grace Systems
cmake_minimum_required(VERSION 2.8)

# Project Name
project(MyProject)

# Languages (Only C for this one)
enable_language(C)

# Create the library
add_library(MillerLib STATIC 
  include/MillerLib.h
  src/MillerLib.c
  include/ProgramConnectors/SharedMemory.h
  src/ProgramConnectors/SharedMemory.c
  include/Threading/MillerThreads.h
  src/Threading/MillerThreads.c
)

# Create the main executable
add_executable(MyProject 
  main.c
)

# Add the library as a dependency to the executable
target_link_libraries(MyProject MillerLib)
