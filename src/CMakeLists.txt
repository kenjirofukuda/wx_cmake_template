cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(wx_cmake_template_core LANGUAGES CXX)
 
message(STATUS "----- src/CMakeLists.txt")
message(STATUS "CMAKE_SOURCE_DIR        =${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR        =${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR=${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(RC_DEST_DIR "${CMAKE_BINARY_DIR}/rc")

# hack for buggy CMake's FindwxWidgets script
if(DEFINED ENV_WX_CONFIG)
    set(ENV{WX_CONFIG} ${ENV_WX_CONFIG})
endif()

set(wxWidgets_USE_STATIC 1)

find_package(wxWidgets REQUIRED core base OPTIONAL_COMPONENTS html xml xrc)

# set(SRCS main.cpp)
set(SRCS main_rc.cpp)

include(${wxWidgets_USE_FILE})

if(APPLE)
    # create bundle on apple compiles
    add_executable(main MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(main WIN32 ${SRCS} main.exe.manifest)
endif()

target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES})

add_custom_command(
  TARGET
  main
  POST_BUILD
  COMMAND rm -f "${RC_DEST_DIR}"
  COMMAND ln -s "${RC_SRC_DIR}" "${RC_DEST_DIR}"
  DEPENDS "${RC_SRC_DIR}")

