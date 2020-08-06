//
// Created by MStefan99 on 4.8.20.
//


#include "BaseChunk.h"


BaseChunk::BaseChunk(const char* filePath, long addr) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);

	type = new char[5];
	fread(type, 4, 1, f);
	type[4] = 0;

	length = read32(f);
	byteLength = length + 8;
}


BaseChunk::BaseChunk(const BaseChunk& chunk) {
	length = chunk.length;
	byteLength = chunk.byteLength;

	type = new char[5];
	for (int i {0}; i < 5; ++i) {
		type[i] = chunk.type[i];
	}
}


BaseChunk::~BaseChunk() {
	delete[] (type);
}


std::string BaseChunk::getType() const {
	return std::string(type);
}


int BaseChunk::getLength() const {
	return length;
}


long BaseChunk::getByteLength() const {
	return byteLength;
}
