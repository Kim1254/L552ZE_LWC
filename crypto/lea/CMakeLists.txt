set(LEA_SOURCE
	lea_base.c
	lea_core.c
	lea_core_xop.c
	lea_gcm_generic.c
	lea_gcm_pclmul.c
	lea_online.c
	lea_t_avx2_sse2.c
	lea_t_avx2_xop.c
	lea_t_fallback.c
	lea_t_generic.c
	lea_t_neon.c
	lea_t_sse2.c
	lea_t_xop.c
	lea.h
	lea_avx2.h
	lea_cbc.h
	lea_cmac.h
	lea_ctr.h
	lea_ecb.h
	lea_gcm.h
	lea_key.h
	lea_locl.h
	lea_neon.h
	lea_ofb.h
	lea_sse2.h
	lea_xop.h
)

add_library(LEA STATIC LEA_SOURCE)
add_library(LEA_TEST STATIC lea_test.c lea_test.h)

target_include_directories(LEA_TEST PRIVATE ../../util)
target_link_libraries(LEA_TEST PRIVATE LEA)