//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_VLQ_H
#define MIDI_PARSER_VLQ_H


#include <cstdio>
#include <cstdint>


class VLQ {
public:
	VLQ() = default;
	VLQ(const char* filePath, long addr);

	[[nodiscard]] uint32_t getData() const;
	[[nodiscard]] uint8_t getByteLength() const;

protected:
	uint32_t data {};
	uint8_t length {};
};

#endif //MIDI_PARSER_VLQ_H
