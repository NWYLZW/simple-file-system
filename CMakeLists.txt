cmake_minimum_required(VERSION 3.20)
project(simple_file_system)

set(CMAKE_CXX_STANDARD 20)

# set build output file dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

# set source file dir
include_directories(src)

# build command
file(
    GLOB login
    "src/core/*.cpp"
    "src/commands/login.cpp"
)
add_executable(login ${login})

# build command
file(
    GLOB dir
    "src/core/*.cpp"
    "src/commands/dir.cpp"
)
add_executable(dir ${dir})

# build main program
file(
    GLOB sfs
    "src/*.cpp"
    "src/core/*.cpp"
)
add_executable(sfs ${sfs})

# set test sub dir
add_subdirectory("test")
