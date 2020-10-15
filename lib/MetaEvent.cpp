//
// Created by MStefan99 on 6.8.20.
//

#include "MetaEvent.h"


MetaEvent::MetaEvent(const char* filePath, long addr) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);

	code = getc(f);
	status = getc(f);
	length = getc(f);
	data = new uint8_t[length];
	byteLength = length + 3;

	for (int i {0}; i < length; ++i) {
		data[i] = getc(f);
	}

	fclose(f);
}


MetaEvent::~MetaEvent() {
	delete[] (data);
}


MetaEvent* MetaEvent::clone() const {
	auto* e = new MetaEvent;

	e->byteLength = byteLength;
	e->code = code;
	e->status = status;
	e->length = length;
	e->data = new uint8_t[length];

	for (int i {0}; i < length; ++i) {
		e->data[i] = data[i];
	}

	return e;
}


MidiType::EventType MetaEvent::getType() const {
	return MidiType::EventType::MetaEvent;
}


MidiType::MetaMessageStatus MetaEvent::getStatus() const {
	return MidiType::MetaMessageStatus(status);
}


uint8_t MetaEvent::getLength() const {
	return length;
}


uint8_t* MetaEvent::getData() const {
	return data;
}

