//
// Created by MStefan99 on 4.8.20.
//

#include "MidiFile.h"


MidiFile::MidiFile(const char* filePath): header(filePath) {
	long addr = header.getByteLength();

	for (int i {0}; i < header.getNTracks(); ++i) {
		TrackChunk track {filePath, addr};
		tracks.push_back(track);
		addr += track.getByteLength();
	}
}
