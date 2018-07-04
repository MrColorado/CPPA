cmake_minimum_required(VERSION 3.9)
project(CPPA)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "-std=c++17 -ggdb -O0 -pedantic -Wall -Wextra -Werror")

set(CMAKE_CXX_FLAGS_RELEASE "-std=c++17 -O3 -pedantic -Wall -Wextra -Werror")

include_directories(src)

file(GLOB_RECURSE SRC_MAIN src/*)

find_package(Boost REQUIRED COMPONENTS program_options system)
include_directories( ${Boost_INCLUDE_DIRS} )

FIND_PACKAGE(Boost REQUIRED COMPONENTS program_options system)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(test ${SRC_MAIN})
TARGET_LINK_LIBRARIES(test LINK_PUBLIC ${Boost_LIBRARIES} )
