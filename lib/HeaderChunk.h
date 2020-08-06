//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_HEADERCHUNK_H
#define MIDI_PARSER_HEADERCHUNK_H


#include <cstdint>
#include "BaseChunk.h"
#include "types.h"


class HeaderChunk: public BaseChunk {
public:
	explicit HeaderChunk(const char* filePath);

	[[nodiscard]] MidiType::FileFormat getFormat() const;
	[[nodiscard]] uint16_t getNTracks() const;
	[[nodiscard]] uint16_t getDivision() const;

protected:
	uint8_t format;
	uint16_t nTracks;
	uint16_t division;
};

#endif //MIDI_PARSER_HEADERCHUNK_H
