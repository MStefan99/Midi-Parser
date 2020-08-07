//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_HEADERCHUNK_H
#define MIDI_PARSER_HEADERCHUNK_H


#include <cstdint>
#include "BaseChunk.h"
#include "types.h"

/**
 * \class HeaderChunk
 * \brief Contains header data of the Midi file
 */
class HeaderChunk: public BaseChunk {
public:
	/**
	 * Reads the Midi file and constructs the chunk object
	 * @param filePath Path to the Midi file to read the chunk data from
	 */
	explicit HeaderChunk(const char* filePath);

	/**
	 * Returns the format of the file
	 * @return Midi file format
	 */
	[[nodiscard]] MidiType::FileFormat getFormat() const;
	/**
	 * Returns number of tracks in the Midi file
	 * @return Number of tracks
	 */
	[[nodiscard]] uint16_t getNTracks() const;
	/**
	 * Returns the time division of the Midi file
	 * @return Time division
	 */
	[[nodiscard]] uint16_t getDivision() const;

protected:
	uint8_t format;
	uint16_t nTracks;
	uint16_t division;
};

#endif //MIDI_PARSER_HEADERCHUNK_H
