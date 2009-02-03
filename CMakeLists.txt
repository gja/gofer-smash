cmake_minimum_required(VERSION 2.6)
project(gofer-smash)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

include_directories( ${CMAKE_SOURCE_DIR} )
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

add_executable(bin2c bin2c.c)

MACRO (bin2c SRC_FILE OUTPUT_FILE VARIABLE)
ADD_CUSTOM_COMMAND(
	OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_FILE}"
	COMMAND "${CMAKE_CURRENT_BINARY_DIR}/bin2c" "${CMAKE_CURRENT_SOURCE_DIR}/${SRC_FILE}" "${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_FILE}"
	DEPENDS bin2c "${CMAKE_CURRENT_SOURCE_DIR}/${SRC_FILE}"
	)
set (${VARIABLE} ${${VARIABLE}} ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_FILE})
ENDMACRO (bin2c SRC_FILE OUTPUT_FILE VARIABLE)

bin2c( data/pow.png pow_png.h IMAGEFILES )
bin2c( data/glove.png glove_png.h IMAGEFILES )
bin2c( data/smash.png smash_png.h IMAGEFILES )
bin2c( data/splat.png splat_png.h IMAGEFILES )
bin2c( data/pie.png pie_png.h IMAGEFILES )

add_custom_target(images DEPENDS ${IMAGEFILES})

add_subdirectory(effects)

set (SOURCES main.cpp selectsmash.cpp game.cpp smash.cpp)
QT4_WRAP_CPP(SOURCES game.h smash.h)

add_executable(gofer-smash ${SOURCES})
add_dependencies(gofer-smash images)
target_link_libraries(gofer-smash ${QT_LIBRARIES} effects)
