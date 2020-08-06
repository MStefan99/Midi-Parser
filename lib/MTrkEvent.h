//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_MTRKEVENT_H
#define MIDI_PARSER_MTRKEVENT_H


#include <cstdint>
#include <cstdio>
#include "VLQ.h"
#include "MidiEvent.h"
#include "SysExEvent.h"
#include "MetaEvent.h"
#include "ReadNumber.h"


class MTrkEvent {
public:
	MTrkEvent(const char* filePath, long addr);
	MTrkEvent(const MTrkEvent& event);
	~MTrkEvent();

	[[nodiscard]] VLQ getDeltaTime() const;
	[[nodiscard]] long getByteLength() const;

protected:
	VLQ deltaTime {};
	Event* event {};
	long byteLength {};
};

#endif //MIDI_PARSER_MTRKEVENT_H
