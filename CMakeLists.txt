# This is the 8th Sem Project of Sourav Sarkar, Tejas Dinkar and Thejaswi K
# Currently This is just the Demo

project(gofer-smash)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

include_directories( ${CMAKE_SOURCE_DIR} )

add_subdirectory(effects)

set (SOURCES main.cpp selectsmash.cpp game.cpp smash.cpp)
QT4_WRAP_CPP(SOURCES game.h smash.h)

add_executable(gofer-smash ${SOURCES})
target_link_libraries(gofer-smash ${QT_LIBRARIES} effects)

add_custom_target (data ALL ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data )
