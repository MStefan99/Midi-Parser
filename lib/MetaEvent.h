//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_METAEVENT_H
#define MIDI_PARSER_METAEVENT_H


#include <cstdio>
#include <cstdint>
#include "types.h"
#include "Event.h"


class MetaEvent: public Event {
public:
	MetaEvent() = default;
	MetaEvent(const char* filePath, long addr);
	~MetaEvent() override;

	[[nodiscard]] MidiType::EventType getType() const override;
	[[nodiscard]] MidiType::MetaMessageStatus getStatus() const;
	[[nodiscard]] uint8_t getLength() const;
	[[nodiscard]] uint8_t* getData() const;

protected:
	[[nodiscard]] Event* clone() const override;

	uint8_t code {};
	uint8_t status {};
	uint8_t length {};
	uint8_t* data {};
};

#endif //MIDI_PARSER_METAEVENT_H
