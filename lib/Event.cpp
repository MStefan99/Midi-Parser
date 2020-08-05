//
// Created by MStefan99 on 4.8.20.
//


#include "Event.h"


Event::Event(const char* filePath, long addr) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);

	status = getc(f);
	uint16_t buf = getc(f);

	// TODO: add different chunk types

	if (buf & 0x80u) {
		buf <<= 8u;
		buf |= (uint8_t)getc(f);
		++byteLength;
	}
	data = buf;
}


uint8_t Event::getStatus() const {
	return status;
}


uint16_t Event::getData() const {
	return data;
}


uint8_t Event::getByteLength() const {
	return byteLength;
}
