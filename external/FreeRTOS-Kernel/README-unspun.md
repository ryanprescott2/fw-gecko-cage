# Changes from mainline
1. Add CMake build support

# CMake build support
## How to use lib
1. Set the config folder using the FREERTOS_CONFIG_FOLDER variable.
Example:
```
set(FREERTOS_CONFIG_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
```
2. Add the subdirectory.
Example:
```
add_subdirectory(../ freertos)
```

Also see the test_cmake folder for working example. 

## Supported compiler/arch configs
- GCC/ARM_CM4F

## Run the CMake build tests
### Pre-Reqs
1. CMake is installed and has been added to the PATH
2. ARM GCC tool chain is installed and has been added to the PATH
3. Make is installed and has been added to the PATH
### Build
1. Configure build (first time only)
```
cmake -S test_cmake -B build --toolchain toolchain.cmake
```
**Note: if cmake picks a generator that isn't installed by default, you can change the generator by adding `-G <name of generator>` to the end of the command**
2. Run the build command:
```
cmake --build build
```
This will create a folder called "build" in the root of the repo that will contain all the built artifacts
