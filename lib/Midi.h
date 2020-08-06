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


class Midi {
public:
	explicit Midi(const char* filePath);

	[[nodiscard]] const HeaderChunk& getHeader() const;
	[[nodiscard]] const LIST<TrackChunk>& getTracks() const;

protected:
	HeaderChunk header;
	LIST<TrackChunk> tracks {};
};

#endif //MIDI_PARSER_MIDI_H
