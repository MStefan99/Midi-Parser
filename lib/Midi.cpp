//
// Created by MStefan99 on 4.8.20.
//

#include "Midi.h"


Midi::Midi(const char* filePath): header(filePath) {
	long addr = header.getByteLength();

	for (int i {0}; i < header.getNTracks(); ++i) {
		TrackChunk track {filePath, addr};
		tracks.push_back(track);
		addr += track.getByteLength();
	}
}


const HeaderChunk& Midi::getHeader() const {
	return header;
}


const LIST<TrackChunk>& Midi::getTracks() const {
	return tracks;
}
