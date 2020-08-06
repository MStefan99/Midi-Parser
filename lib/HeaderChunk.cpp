//
// Created by MStefan99 on 4.8.20.
//

#include "HeaderChunk.h"


HeaderChunk::HeaderChunk(const char* filePath):
		BaseChunk(filePath, 0l) {

	FILE* f = fopen(filePath, "rb");
	fseek(f, 8, SEEK_SET);
	format = read16(f);
	nTracks = read16(f);
	division = read16(f);

	fclose(f);
}


MidiType::FileFormat HeaderChunk::getFormat() const {
	return MidiType::FileFormat(format);
}


uint16_t HeaderChunk::getNTracks() const {
	return nTracks;
}


uint16_t HeaderChunk::getDivision() const {
	return division;
}

