cmake_minimum_required(VERSION 3.10)
project(Plazza)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g3")

include_directories(include)

file(GLOB SRC_FILES "src/*.cpp" "main.cpp")

add_executable(plazza ${SRC_FILES})

target_link_libraries(plazza pthread)

add_custom_target(custom_clean COMMAND ${CMAKE_COMMAND} -E rm -f /tmp/kitchen_pipe_* DEPENDS clean)
