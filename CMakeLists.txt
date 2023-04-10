cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(wx_cmake_template LANGUAGES CXX)

message(STATUS "----- CMakeLists.txt")
message(STATUS "CMAKE_SOURCE_DIR        =${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR        =${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR=${CMAKE_CURRENT_BINARY_DIR}")

message(STATUS "wxWidgets_ROOT_DIR=${wxWidgets_ROOT_DIR}")
message(STATUS "wxWidgets_LIB_DIR=${wxWidgets_LIB_DIR}")
message(STATUS "wxWidgets_CONFIGURATION=${wxWidgets_CONFIGURATION}")


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(RC_SRC_DIR "${CMAKE_SOURCE_DIR}/rc")

# ExternalProject base
set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)

set(STAGED_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage)

add_subdirectory(thirdparty)

include(ExternalProject)
ExternalProject_Add(${PROJECT_NAME}_core
  DEPENDS
  wxWidgets_external
  SOURCE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  CMAKE_ARGS
  -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}

  -DwxWidgets_ROOT_DIR=${wxWidgets_ROOT_DIR}
  -DENV_WX_CONFIG=${ENV_WX_CONFIG}
  CMAKE_CACHE_ARGS
  -DCMAKE_PREFIX_PATH:PATH=${CMAKE_PREFIX_PATH}
  BUILD_ALWAYS
  1
  INSTALL_COMMAND
  ""
)
