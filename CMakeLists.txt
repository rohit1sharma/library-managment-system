cmake_minimum_required(VERSION 3.16)

project(LibraryManagementSystem VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect source files
file(GLOB_RECURSE SOURCES
    backend/*.cpp
    database/*.cpp
)

# Create executable
add_executable(library_backend ${SOURCES})

# Include directories
target_include_directories(library_backend PRIVATE
    backend
    backend/student
    backend/librarian
    database
)


# Enable warnings
target_compile_options(library_backend PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

target_link_libraries(library_backend PRIVATE mysqlclient)
