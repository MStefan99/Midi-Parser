//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_VLQ_H
#define MIDI_PARSER_VLQ_H


#include <cstdio>
#include <cstdint>


/**
 * \class VLQ
 * \brief Represents variable-length quantity of the MTrkEvent
 */
class VLQ {
public:
	/**
	 * Default constructor
	 */
	VLQ() = default;
	/**
	 * Reads the Midi file and constructs the VLQ object
	 * @param filePath Path to the Midi file to read
	 * @param addr Address of the VLQ data in bytes
	 */
	VLQ(const char* filePath, long addr);

	/**
	 * Returns the VLQ value
	 * @return The value of the VLQ
	 */
	[[nodiscard]] uint32_t getData() const;
	/**
	 * Returns the VLQ length
	 * @return Length of the VLQ in bytes
	 */
	[[nodiscard]] uint8_t getByteLength() const;

protected:
	uint32_t data {};
	uint8_t length {};
};

#endif //MIDI_PARSER_VLQ_H
