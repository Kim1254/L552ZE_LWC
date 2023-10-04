add_library(ENOCORO STATIC enocoro.c enocoro.h)
add_library(ENOCORO_TEST STATIC enocoro_test.c enocoro_test.h)

target_include_directories(ENOCORO_TEST PRIVATE ../../util)
target_link_libraries(ENOCORO_TEST PRIVATE ENOCORO)