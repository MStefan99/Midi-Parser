//
// Created by MStefan99 on 4.8.20.
//

#include "MTrkEvent.h"


MTrkEvent::MTrkEvent(const char* filePath, long addr):
		deltaTime(VLQ(filePath, addr)) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr + deltaTime.getByteLength(), SEEK_SET);

	uint8_t status = getc(f);
	byteLength = deltaTime.getByteLength();
	addr += deltaTime.getByteLength();

	switch (status) {
		case 0xF0u:
		case 0xF7u:
			event = new SysExEvent(filePath, addr);
			break;
		case 0xFFu:
			event = new MetaEvent(filePath, addr);
			break;
		default:
			event = new MidiEvent(filePath, addr);
			break;
	}
	byteLength += event->getByteLength();
}


long MTrkEvent::getByteLength() const {
	return byteLength;
}
