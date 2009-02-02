set(EFFECTS boxing.cpp)

QT4_WRAP_CPP(EFFECTS boxing.h)

add_library(effects ${EFFECTS})
add_dependencies(effects images)
