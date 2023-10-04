if (CRYPTO_TYPE)
	add_subdirectory(${CRYPTO_TYPE})
	target_include_directories(${APP_TARGET} PRIVATE ${CRYPTO_TYPE})
endif()