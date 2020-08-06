//
// Created by MStefan99 on 6.8.20.
//

#include "MetaEvent.h"


MetaEvent::MetaEvent(const char* filePath, long addr) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);

	code = getc(f);
	type = getc(f);
	length = getc(f);
	data = new uint8_t[length];
	byteLength = length + 3;

	for (int i {0}; i < length; ++i) {
		data[i] = getc(f);
	}
}