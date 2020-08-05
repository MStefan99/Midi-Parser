//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_HEADERCHUNK_H
#define MIDI_PARSER_HEADERCHUNK_H


#include "BaseChunk.h"
#include <cstdint>


class HeaderChunk : public BaseChunk {
public:
	typedef enum {
		SingleTrack = 0,  // Files which only contain a single track
		SimTracks = 1,  // Files which contain multiple tracks played simultaneously
		IndTracks = 2  // Files which contain multiple tracks played independently
	} Format;


	explicit HeaderChunk(const char* filePath);

	[[nodiscard]] Format getFormat() const;
	[[nodiscard]] uint16_t getNTracks() const;
	[[nodiscard]] uint16_t getDivision() const;

protected:
	Format format;
	uint16_t nTracks;
	uint16_t division;
};

#endif //MIDI_PARSER_HEADERCHUNK_H
