//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_TRACKCHUNK_H
#define MIDI_PARSER_TRACKCHUNK_H


#include "BaseChunk.h"
#include "Event.h"
#include "VLQ.h"
#include "MTrkEvent.h"
#include <list>
#include <cstdint>


struct TrackChunk : public BaseChunk {
public:
	TrackChunk(const char* filePath, long addr);

protected:
	std::list<MTrkEvent> events {};
};

#endif //MIDI_PARSER_TRACKCHUNK_H
