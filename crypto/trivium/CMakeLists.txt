add_library(TRIVIUM STATIC trivium.c trivium.h)
add_library(TRIVIUM_TEST STATIC trivium_test.c trivium_test.h)

target_include_directories(TRIVIUM_TEST PRIVATE ../../util)
target_link_libraries(TRIVIUM_TEST PRIVATE TRIVIUM)