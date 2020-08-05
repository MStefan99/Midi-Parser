//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_MTRKEVENT_H
#define MIDI_PARSER_MTRKEVENT_H


#include <cstdint>
#include "VLQ.h"
#include "Event.h"
#include "ReadNumber.h"


class MTrkEvent : public Event {

public:
	MTrkEvent(const char* filePath, long addr);

protected:
	VLQ deltaTime {};
};

#endif //MIDI_PARSER_MTRKEVENT_H
