//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_EVENT_H
#define MIDI_PARSER_EVENT_H


#include <cstdint>
#include <cstdio>
#include "types.h"


class Event {
public:
	virtual ~Event() = default;

	[[nodiscard]] virtual Event* clone() const = 0;
	[[nodiscard]] virtual MidiType::EventType getType() const = 0;

	[[nodiscard]] uint8_t getByteLength() const;

protected:
	uint8_t byteLength {};
};

#endif //MIDI_PARSER_EVENT_H
