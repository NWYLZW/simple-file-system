cmake_minimum_required(VERSION 3.20)
project(simple_file_system)

set(CMAKE_CXX_STANDARD 20)

file(
    GLOB
    mainSources "src/core/*.cpp" "src/*.cpp"
)

add_executable(
    simple_file_system
    ${mainSources}
)

file(
    GLOB
    login "src/commands/login.cpp"
)

add_executable(
    login ${login}
)
