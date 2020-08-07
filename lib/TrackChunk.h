//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_TRACKCHUNK_H
#define MIDI_PARSER_TRACKCHUNK_H


#include <cstdint>
#include "BaseChunk.h"
#include "Event.h"
#include "VLQ.h"
#include "MTrkEvent.h"
#include "Options.h"

#if USE_STL
#include <list>
#else
#include "list.h"
#endif


/**
 * \class TrackChunk
 * \brief Contains track data
 */
struct TrackChunk: public BaseChunk {
public:
	/**
	 * Reads the Midi file and constructs the chunk object
	 * @param filePath Path to the Midi file to read
	 * @param addr Address of the chunk in bytes
	 */
	TrackChunk(const char* filePath, long addr);

	/**
	 * Returns track events
	 * @return List of the track events
	 */
	[[nodiscard]] const LIST<MTrkEvent>& getEvents() const;

protected:
	LIST<MTrkEvent> events {};
};

#endif //MIDI_PARSER_TRACKCHUNK_H
