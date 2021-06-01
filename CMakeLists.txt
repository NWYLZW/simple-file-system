cmake_minimum_required(VERSION 3.20)
project(simple_file_system)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

file(
    GLOB
    login "src/commands/login.cpp"
)

add_executable(
    login ${login}
)

file(
    GLOB
    main "src/core/*.cpp" "src/*.cpp"
)

add_executable(
    main ${main}
)
