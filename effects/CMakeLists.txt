set(EFFECTS boxing.cpp pie.cpp)

QT4_WRAP_CPP(EFFECTS boxing.h pie.h)

add_library(effects ${EFFECTS})
add_dependencies(effects images)
