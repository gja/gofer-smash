# This is the 8th Sem Project of Sourav Sarkar, Tejas Dinkar and Thejaswi K
# Currently This is just the Demo

project(gofer-smash)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

include_directories( ${CMAKE_SOURCE_DIR} )
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

add_executable(bin2c bin2c.c)

ADD_CUSTOM_COMMAND(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/pow_png.h
	COMMAND ${CMAKE_CURRENT_BINARY_DIR}/bin2c ${CMAKE_CURRENT_SOURCE_DIR}/data/pow.png ${CMAKE_CURRENT_BINARY_DIR}/pow_png.h
	DEPENDS bin2c ${CMAKE_CURRENT_SOURCE_DIR}/data/pow.png
	)

ADD_CUSTOM_COMMAND(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/glove_png.h
	COMMAND ${CMAKE_CURRENT_BINARY_DIR}/bin2c ${CMAKE_CURRENT_SOURCE_DIR}/data/glove.png ${CMAKE_CURRENT_BINARY_DIR}/glove_png.h
	DEPENDS bin2c ${CMAKE_CURRENT_SOURCE_DIR}/data/glove.png
	)

ADD_CUSTOM_COMMAND(
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/smash_png.h
	COMMAND ${CMAKE_CURRENT_BINARY_DIR}/bin2c ${CMAKE_CURRENT_SOURCE_DIR}/data/smash.png ${CMAKE_CURRENT_BINARY_DIR}/smash_png.h
	DEPENDS bin2c ${CMAKE_CURRENT_SOURCE_DIR}/data/smash.png
	)

add_custom_target(images DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/pow_png.h
	${CMAKE_CURRENT_BINARY_DIR}/glove_png.h
	${CMAKE_CURRENT_BINARY_DIR}/smash_png.h
	)

add_subdirectory(effects)

set (SOURCES main.cpp selectsmash.cpp game.cpp smash.cpp)
QT4_WRAP_CPP(SOURCES game.h smash.h)

add_executable(gofer-smash ${SOURCES})
add_dependencies(gofer-smash images)
target_link_libraries(gofer-smash ${QT_LIBRARIES} effects)
