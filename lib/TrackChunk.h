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



struct TrackChunk: public BaseChunk {
public:
	TrackChunk(const char* filePath, long addr);

	[[nodiscard]] const LIST<MTrkEvent>& getEvents() const;

protected:
	LIST<MTrkEvent> events {};
};

#endif //MIDI_PARSER_TRACKCHUNK_H
