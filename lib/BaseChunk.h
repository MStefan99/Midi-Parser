//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_BASECHUNK_H
#define MIDI_PARSER_BASECHUNK_H


#include <cstdio>
#include <string>
#include <cstdint>
#include "ReadNumber.h"


class BaseChunk {
public:
	[[nodiscard]] std::string getType() const;
	[[nodiscard]] int getLength() const;
	[[nodiscard]] long getByteLength() const;

public:
	BaseChunk(const char* filePath, long addr);
	BaseChunk(const BaseChunk& chunk);
	~BaseChunk();

protected:
	char* type {};
	uint32_t length {};
	long byteLength {};
};

#endif //MIDI_PARSER_BASECHUNK_H
