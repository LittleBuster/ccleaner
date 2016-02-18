cmake_minimum_required(VERSION 2.8)
project(ccleaner)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS system thread filesystem REQUIRED)

include_directories(".")
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -pedantic -Wall -O2")
set(SRC_LIST app.cpp main.cpp configs.cpp cleaner.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

install (FILES build/ccleaner DESTINATION /usr/share/ccleaner/)
install (FILES ccleaner.cfg DESTINATION /etc/)
