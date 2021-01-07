cmake_minimum_required(VERSION 3.17)
project(TDDoc)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES *.hpp *.cpp)

add_executable(TDDoc ${SOURCES})

if(WIN32)
    target_include_directories(TDDoc PRIVATE "C:/dev/libs/freeglut/include")
    target_link_directories(TDDoc PRIVATE "C:/dev/libs/freeglut/lib/x64")
    target_link_libraries(TDDoc opengl32 freeglut)
endif()
