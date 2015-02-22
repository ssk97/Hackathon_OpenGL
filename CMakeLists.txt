cmake_minimum_required(VERSION 2.8)
project(tale_of_two_circles)

set(CMAKE_CXX_FLAGS "-std=c++11")

file(GLOB SOURCE "*.cpp")

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module( GLFW3 REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)

include_directories(${GLFW3_INCLUDE_DIR})
add_executable(tale_of_two_circles ${SOURCE})

target_link_libraries(tale_of_two_circles ${GLFW3_STATIC_LIBRARIES} ${GLEW_LIBRARIES})
if(APPLE)
  target_link_libraries(tale_of_two_circles "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
endif()
