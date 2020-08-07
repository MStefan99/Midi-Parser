//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_MIDIEVENT_H
#define MIDI_PARSER_MIDIEVENT_H


#include <cstdint>
#include <cstdio>
#include "types.h"
#include "Event.h"


class MidiEvent: public Event {
public:
	MidiEvent(const char* filePath, long addr);
	~MidiEvent() override = default;
	[[nodiscard]] Event * clone() const override;

	[[nodiscard]] MidiType::EventType getType() const override;
	[[nodiscard]] MidiType::MidiMessageStatus getStatus() const;
	[[nodiscard]] uint8_t getChannel() const;
	[[nodiscard]] uint8_t getNote() const;
	[[nodiscard]] uint8_t getVelocity() const;
	[[nodiscard]] uint16_t getData() const;

protected:
	static uint8_t lastStatus;

	uint8_t status {};
	uint16_t data {};
};

#endif //MIDI_PARSER_MIDIEVENT_H
