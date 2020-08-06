//
// Created by MStefan99 on 6.8.20.
//

#include "SysExEvent.h"


SysExEvent::SysExEvent(const char* filePath, long addr) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);

	code = getc(f);
	length = getc(f);
	data = new uint8_t[length];
	byteLength = length + 2;

	for (int i {0}; i < length; ++i) {
		data[i] = getc(f);
	}
}


Event* SysExEvent::clone() const {
	auto* e = new SysExEvent;

	e->code = code;
	e->length = length;
	e->data = new uint8_t[length];

	for (int i {0}; i < length; ++i) {
		e->data[i] = data[i];
	}

	return e;
}


SysExEvent::~SysExEvent() {
	delete[] (data);
}
