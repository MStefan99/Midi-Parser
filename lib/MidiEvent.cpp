//
// Created by MStefan99 on 6.8.20.
//

#include "MidiEvent.h"


uint8_t MidiEvent::lastStatus {0};


MidiEvent::MidiEvent(const char* filePath, long addr) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);
	this->status = getc(f);

	if (status & 0x80u) {
		lastStatus = status;
		byteLength = 1;
	} else {
		status = lastStatus;
		fseek(f, -1, SEEK_CUR);
	}

	switch (status & 0xF0u) {
		case 0xC0:
		case 0xD0:
			data = getc(f);
			++byteLength;
			break;
		case 0x80:
		case 0x90:
		case 0xA0:
		case 0xB0:
		case 0xE0:
			data = getc(f) << 8u | getc(f);
			byteLength += 2;
			break;
	}

	fclose(f);
}


Event* MidiEvent::clone() const {
	return new MidiEvent(*this);
}


MidiType::MidiMessageStatus MidiEvent::getStatus() const {
	return MidiType::MidiMessageStatus(status & 0xF0u);
}


uint16_t MidiEvent::getData() const {
	return data;
}


MidiType::EventType MidiEvent::getType() const {
	return MidiType::MidiEvent;
}

