//
// Created by MStefan99 on 4.8.20.
//


#include "VLQ.h"


VLQ::VLQ(const char* filePath, long addr): length {0}, data {0} {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);
	uint8_t byte;

	byte = getc(f);
	this->data = byte & 0x7fu;
	this->length = 1;

	if (byte & 0x80u) {
		do {
			++this->length;
			this->data <<= 7u;
			this->data |= (byte = getc(f)) & 0x7fu;
		} while (byte & 0x80u);
	}
}


uint32_t VLQ::getData() const {
	return this->data;
}


uint8_t VLQ::getByteLength() const {
	return this->length;
}
