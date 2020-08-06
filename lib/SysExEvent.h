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
	SysExEvent() = default;
	SysExEvent(const char* filePath, long addr);
	~SysExEvent() override;
	[[nodiscard]] Event* clone() const override;

	[[nodiscard]] MidiType::EventType getType() const override;
	[[nodiscard]] MidiType::SysExMessageStatus getStatus() const;
	[[nodiscard]] uint8_t getLength() const;
	[[nodiscard]] uint8_t* getData() const;

protected:
	uint8_t status {};
	uint8_t length {};
	uint8_t* data {};
};

#endif //MIDI_PARSER_SYSEXEVENT_H
