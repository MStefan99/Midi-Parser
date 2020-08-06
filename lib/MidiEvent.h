//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_MIDIEVENT_H
#define MIDI_PARSER_MIDIEVENT_H


#include <cstdint>
#include <cstdio>
#include "Event.h"


class MidiEvent: public Event {
public:
	MidiEvent(const char* filePath, long addr);
	~MidiEvent() override = default;

	Event * clone() const override;

	[[nodiscard]] uint8_t getStatus() const;
	[[nodiscard]] uint16_t getData() const;

protected:
	static uint8_t lastStatus;

	uint8_t status {};
	uint16_t data {};
};

#endif //MIDI_PARSER_MIDIEVENT_H
