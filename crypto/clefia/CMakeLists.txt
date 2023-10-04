add_library(CLEFIA STATIC clefia.c clefia.h)
add_library(CLEFIA_TEST STATIC clefia_test.c clefia_test.h)

target_include_directories(CLEFIA_TEST PRIVATE ../../util)
target_link_libraries(CLEFIA_TEST PRIVATE CLEFIA)