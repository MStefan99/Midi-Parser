//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_BASECHUNK_H
#define MIDI_PARSER_BASECHUNK_H


#include <cstdio>
#include <cstdint>
#include "ReadNumber.h"


/**
 * \class BaseChunk
 * \brief A base class for any chunk
 */
class BaseChunk {
public:
	/**
	 * Reads the Midi file and constructs the chunk object
	 * @param filePath A path to the file to read the chunk data from
	 * @param addr An address of the chunk in bytes
	 */
	BaseChunk(const char* filePath, long addr);
	/**
	 * Copies the chunk
	 * @param chunk Chunk to copy from
	 */
	BaseChunk(const BaseChunk& chunk);
	/**
	 * Destroys the chunk object
	 */
	~BaseChunk();

	/**
	 * Returns the name of the chunk
	 * @return A pointer to the chunk name. A name is always 4 characters long
	 */
	[[nodiscard]] char* getName() const;
	/**
	 * Returns the length of the chunk
	 * @return Length of the chunk, excluding the name and the length itself
	 */
	[[nodiscard]] int getLength() const;
	/**
	 * Returns the length of the chunk
	 * @return Length of the chunk with name and length bytes included
	 */
	[[nodiscard]] long getByteLength() const;

protected:
	char* name {};
	uint32_t length {};
	long byteLength {};
};

#endif //MIDI_PARSER_BASECHUNK_H
