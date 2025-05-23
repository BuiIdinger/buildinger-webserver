cmake_minimum_required(VERSION 3.31)

# Allow targets to be modified from outside
cmake_policy(SET CMP0079 NEW)

project(buildinger_webserver
        VERSION 1.0.0
        DESCRIPTION "C++ WebServer."
        LANGUAGES CXX
)

# Set some C++ standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set build type
set(CMAKE_BUILD_TYPE Debug)

set(BWS_PROJECT_NAME buildinger_webserver)

add_subdirectory(src)

# Include headers in the include directory
target_include_directories(${BWS_PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/include)