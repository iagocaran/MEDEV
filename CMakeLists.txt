cmake_minimum_required(VERSION 3.17)
project(TDDoc)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES src/*.cpp)

add_executable(TDDoc ${SOURCES})

include_directories(include)

find_package(OpenGL REQUIRED)

find_package(GLUT REQUIRED)

target_include_directories(TDDoc PRIVATE ${GLUT_INCLUDE_DIR})
target_include_directories(TDDoc PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(TDDoc ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

