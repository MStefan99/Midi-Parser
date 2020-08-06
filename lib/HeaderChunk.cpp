//
// Created by MStefan99 on 4.8.20.
//

#include "HeaderChunk.h"


HeaderChunk::HeaderChunk(const char* filePath):
		BaseChunk(filePath, 0l) {

	FILE* f = fopen(filePath, "rb");
	fseek(f, 8, SEEK_SET);
	this->format = Format(read16(f));
	this->nTracks = read16(f);
	this->division = read16(f);
}


HeaderChunk::Format HeaderChunk::getFormat() const {
	return this->format;
}


uint16_t HeaderChunk::getNTracks() const {
	return nTracks;
}


uint16_t HeaderChunk::getDivision() const {
	return division;
}

