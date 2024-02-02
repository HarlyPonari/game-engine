cmake_minimum_required(VERSION 3.0)

project(game-engine)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/glfw)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)

target_include_directories(${PROJECT_NAME} 
  PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} 
  glfw
)



