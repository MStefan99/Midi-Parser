//
// Created by MStefan99 on 4.8.20.
//


#include "BaseChunk.h"


BaseChunk::BaseChunk(const char* filePath, long addr) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);

	name = new char[5];
	fread(name, 4, 1, f);
	name[4] = 0;

	length = read32(f);
	byteLength = length + 8;

	fclose(f);
}


BaseChunk::BaseChunk(const BaseChunk& chunk) {
	length = chunk.length;
	byteLength = chunk.byteLength;

	name = new char[5];
	for (int i {0}; i < 5; ++i) {
		name[i] = chunk.name[i];
	}
}


BaseChunk::~BaseChunk() {
	delete[] (name);
}


char* BaseChunk::getName() const {
	return name;
}


int BaseChunk::getLength() const {
	return length;
}


long BaseChunk::getByteLength() const {
	return byteLength;
}
