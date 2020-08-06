//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_SYSEXEVENT_H
#define MIDI_PARSER_SYSEXEVENT_H


#include <cstdio>
#include <cstdint>
#include "Event.h"


class SysExEvent: public Event {
public:
	SysExEvent(const char* filePath, long addr);

protected:
	uint8_t code;
	uint8_t length;
	uint8_t* data;
};

#endif //MIDI_PARSER_SYSEXEVENT_H
