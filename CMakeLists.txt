cmake_minimum_required(VERSION 3.10)

project(HotelManagementApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp" "src/database/*.cpp" "src/models/*.cpp" "src/ui/*.cpp" "src/utils/*.cpp")

# Add executable
add_executable(HotelManagementApp ${SOURCES})

# Link MySQL libraries
target_link_libraries(HotelManagementApp mysqlclient)
