add_library(LEA STATIC lea_core.c)
add_library(LEA_TEST STATIC lea_test.c lea_test.h)

target_include_directories(LEA_TEST PRIVATE ../../util)
target_link_libraries(LEA_TEST PRIVATE LEA)