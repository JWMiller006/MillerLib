# Miller Lib
-- -

## What is Miller Lib
-- -
Miller Lib is a simple library that is build for systems running 
C Standard 90 or newer (as in 1990). Though this may seem redundant
and overcomplicated, this is meant to bring the inventions of today
back into a compatible format for the systems of yesterday. Built on
the UMD Grace server (a server running very low specs with an older
version of gcc and cmake installed) and tested on the latest Ubuntu
builds on Github, this library should be able to handle just about 
any C/C++ scenario that you may need. 

## How to Install 
-- -
This repository comes with an example project and the setup for 
compiling into both a static and dynamic libraries and the 
header files are extracted for quick and easy inclusion into 
whatever project setup. Follow the ensuing steps to build the 
project and make sure that the library has built correctly. 

1. Clone the repository: 
    `git clone --recurse-submodules https://github.com/JWMiller006/MillerLib.git`
2. Open the directory and make the build folder: 
    `cd MillerLib && mkdir build && cd build`
3. Generate the CMake files (ensure that there are no errors):
    `cmake ..`
4. Build the project (ensure that there are no errors): 
    `make`
5. Run the example project
    * Linux: `./MyProject`
    * Windows: `./MyProject.exe`

## Limitations
-- -
Note that currently there are some portions of this project that 
are not yet made fully cross platform and I am in the process of 
doing that, yet it is not yet complete (i.e. There is a known 
bug in including the shared memory part of the library on Windows
since the header files and the syntax is different, but that has
not been messed with yet)

