//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_METAEVENT_H
#define MIDI_PARSER_METAEVENT_H


#include <cstdio>
#include <cstdint>
#include "Event.h"


class MetaEvent: public Event {
public:
	MetaEvent(const char* filePath, long addr);

protected:
	uint8_t code;
	uint8_t type;
	uint8_t length;
	uint8_t* data;
};

#endif //MIDI_PARSER_METAEVENT_H
