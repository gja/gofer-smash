cmake_minimum_required(VERSION 2.6)
project(gofer-smash)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

include_directories( ${CMAKE_SOURCE_DIR} )
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

add_custom_target(images DEPENDS ${IMAGEFILES})

add_subdirectory(effects)

set (SOURCES main.cpp selectsmash.cpp game.cpp smash.cpp)
QT4_WRAP_CPP(SOURCES game.h smash.h)
QT4_ADD_RESOURCES(SOURCES gofer.qrc)

add_executable(gofer-smash ${SOURCES})
add_dependencies(gofer-smash images)
target_link_libraries(gofer-smash ${QT_LIBRARIES} effects)
