//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_MIDI_H
#define MIDI_PARSER_MIDI_H


#include "HeaderChunk.h"
#include "TrackChunk.h"
#include "Options.h"


#if USE_STL
#include <list>
#else
#include "list.h"
#endif

/**
 * \class Midi
 * \brief Midi object represents the entire content of a Midi file and is a starting point to using Midi Parser
 *
 * Objects of this class represent the entire contents of a Midi file and provide methods for reading the
 * data stored in the file.
 */
class Midi {
public:
	/**
	 * Constructs the Midi object provided the file name
	 * @param filePath File to read Midi data from
	 */
	explicit Midi(const char* filePath);

	/**
	 * Returns the header of the file
	 * @return Midi header object containing the header data
	 */
	[[nodiscard]] const HeaderChunk& getHeader() const;
	/**
	 * Returns the track list of the Midi file
	 * @return A list containing the tracks in the Midi file
	 */
	[[nodiscard]] const LIST<TrackChunk>& getTracks() const;

protected:
	HeaderChunk header;
	LIST<TrackChunk> tracks {};
};

#endif //MIDI_PARSER_MIDI_H
