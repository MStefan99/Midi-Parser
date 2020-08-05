//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_EVENT_H
#define MIDI_PARSER_EVENT_H


#include <cstdint>
#include <cstdio>


class Event {
public:
	[[nodiscard]] uint8_t getStatus() const;
	[[nodiscard]] uint16_t getData() const;
	[[nodiscard]] uint8_t getByteLength() const;

protected:
	Event(const char* filePath, long addr);

	uint8_t status;
	uint16_t data;
	uint8_t byteLength {2};
};

#endif //MIDI_PARSER_EVENT_H
