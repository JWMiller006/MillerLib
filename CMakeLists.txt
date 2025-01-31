# Must be 2.8 for the Grace Systems
cmake_minimum_required(VERSION 2.8)

# Project Name
project(MyProject)

# Languages (Only C for this one)
enable_language(C)

set(SOURCES 
  include/MillerLib.h
  src/MillerLib.c
  include/MillerTypeDef.h
  include/ProgramConnectors/SharedMemory.h
  src/ProgramConnectors/SharedMemory.c
  include/Threading/MillerThreads.h
  src/Threading/MillerThreads.c
  include/Structures/Array.h
  src/Structures/Array.c
)

# Create the static library
add_library(MillerLib STATIC 
  ${SOURCES}
)

# Create the dynamic library
add_library(MillerLibDyn SHARED
  ${SOURCES}
)

# Create the main executable
add_executable(MyProject 
  main.c
)

# Add the library as a dependency to the executable
target_link_libraries(MyProject MillerLibDyn)

