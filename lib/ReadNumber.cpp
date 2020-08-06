//
// Created by MStefan99 on 5.8.20.
//

#include "ReadNumber.h"


uint16_t read16(FILE* f) {
	uint8_t bytes[2] {};

	fread(bytes, 2, 1, f);
#if USE_BIG_ENDIAN
	return bytes[1] << 8u | bytes[0];
#else
	return bytes[0] << 8u | bytes[1];
#endif
}


uint32_t read32(FILE* f) {
	uint8_t bytes[4] {};

	fread(bytes, 4, 1, f);
#if USE_BIG_ENDIAN
	return bytes[3] << 24u | bytes[2] << 16u | bytes[1] << 8 | bytes[0];
#else
	return bytes[0] << 24u | bytes[1] << 16u | bytes[2] << 8 | bytes[3];
#endif
}