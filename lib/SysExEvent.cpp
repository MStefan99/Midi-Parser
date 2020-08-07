//
// Created by MStefan99 on 6.8.20.
//

#include "SysExEvent.h"


SysExEvent::SysExEvent(const char* filePath, long addr) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);

	status = getc(f);
	length = getc(f);
	data = new uint8_t[length];
	byteLength = length + 2;

	for (int i {0}; i < length; ++i) {
		data[i] = getc(f);
	}

	fclose(f);
}


Event* SysExEvent::clone() const {
	auto* e = new SysExEvent;

	e->status = status;
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


MidiType::EventType SysExEvent::getType() const {
	return MidiType::EventType::SysExEvent;
}


MidiType::SysExMessageStatus SysExEvent::getStatus() const {
	return MidiType::SysExMessageStatus(status);
}


uint8_t SysExEvent::getLength() const {
	return length;
}


uint8_t* SysExEvent::getData() const {
	return data;
}

