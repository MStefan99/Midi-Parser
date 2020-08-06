//
// Created by MStefan99 on 4.8.20.
//


#include "BaseChunk.h"


BaseChunk::BaseChunk(const char* filePath, long addr) {
	FILE* f = fopen(filePath, "rb");
	fseek(f, addr, SEEK_SET);

	this->type = new char[5];
	fread(this->type, 4, 1, f);
	this->type[5] = 0;

	this->length = read32(f);
	this->byteLength = this->length + 8;
}


BaseChunk::BaseChunk(const char* type, uint32_t length): length {length} {
	this->type = new char[5];

	for (int i {0}; i < 4 && type[i]; ++i) {
		this->type[i] = type[i];
	}
	this->type[4] = 0;
}


BaseChunk::~BaseChunk() {
	delete[] (this->type);
}


std::string BaseChunk::getType() const {
	return std::string(type);
}


int BaseChunk::getLength() const {
	return this->length;
}


long BaseChunk::getByteLength() const {
	return this->byteLength;
}
