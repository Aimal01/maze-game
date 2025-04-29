cmake_minimum_required(VERSION 3.10)
project(MazeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(maze_game ${SOURCES})

# Link SFML
target_link_libraries(maze_game 
    sfml-graphics 
    sfml-window 
    sfml-system 
    sfml-audio
)