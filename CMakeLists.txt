cmake_minimum_required(VERSION 3.16)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

project(game-engine)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/glad)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glfw)

set(CMAKE_CXX_STANDARD 17)



file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable("${CMAKE_PROJECT_NAME}")

set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 17)


target_include_directories(${PROJECT_NAME} 
  PUBLIC ${CMAKE_SOURCE_DIR}/inc
  #PUBLIC ${CMAKE_SOURCE_DIR}/external/glfw/src
  #PUBLIC ${CMAKE_SOURCE_DIR}/external/glad/include
  #PUBLIC ${CMAKE_SOURCE_DIR}/external/glad/src
  PUBLIC ${CMAKE_SOURCE_DIR}/external
)

target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})

target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/inc/")

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE glad glfw)



