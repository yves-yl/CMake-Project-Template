# Introduce

This is My CMake Project Template for multiple-directory.

It aims to build targets in sub-directory easier than before 

I used to be modifying CMakeLists.txt everytime when i add new sub directory.

And now,i just need to add CMakeLists.txt in  sub-directory  without changing  main-CMakeLists.txt



# Notice

The cmake/aux_cpp.cmake is not needed.

it is only a demo for cmake module file.

it can generate target name from the prefix of source code.

e.g. 

./demo3/demo3.cpp (source code)   ------> demo3 (target  )

Make sure that the source code file have diffrent prefix name if you use aux_cpp.cmake 

# Directory Structure

./

|__CMakeLists.txt (main-CMakeLists.txt)

|__cmake (cmake module dir)

​	|__aux_cpp.cmake 

|__bin (output binary  here)

|__build (cmake build path )

|__ch3 (sub-dir)

​	|__CMakeLists.txt (sub-CMakeLists.txt)

​	|__ch3.cpp 

|__ch4 (sub-dir)

​	|__CMakeLists.txt (sub-CMakeLists.txt)

​	|__ch4.cpp 

|__ch5 (sub-dir)

​	|__CMakeLists.txt (sub-CMakeLists.txt)

​	|__ch5.cpp 

|__ch13 (sub-dir)

​	|__CMakeLists.txt (sub-CMakeLists.txt)

​	|__ch13 .cpp 

|__demo3 (sub-dir)

​	|__CMakeLists.txt (sub-CMakeLists.txt)

​	|__demo3.cpp 

|__ReadMe.md



