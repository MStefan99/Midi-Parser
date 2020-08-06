//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_MIDIFILE_H
#define MIDI_PARSER_MIDIFILE_H


#include <list>
#include "list.h"
#include "HeaderChunk.h"
#include "TrackChunk.h"


class MidiFile {
public:
	explicit MidiFile(const char* filePath);

protected:
	HeaderChunk header;
	std::list<TrackChunk> tracks {};
};

#endif //MIDI_PARSER_MIDIFILE_H
