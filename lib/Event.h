//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_EVENT_H
#define MIDI_PARSER_EVENT_H


#include <cstdint>
#include <cstdio>


class Event {
public:
	[[nodiscard]] uint8_t getByteLength() const;
	virtual ~Event() = default;

	[[nodiscard]] virtual Event* clone() const = 0;

protected:
	uint8_t byteLength {};
};

#endif //MIDI_PARSER_EVENT_H
