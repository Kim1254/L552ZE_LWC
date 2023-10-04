add_library(AES STATIC aes.c aes.h)
add_library(AES_TEST STATIC aes_test.c aes_test.h)

target_include_directories(AES_TEST PRIVATE ../../util)
target_link_libraries(AES_TEST PRIVATE AES)