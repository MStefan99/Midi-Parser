//
// Created by MStefan99 on 5.8.20.
//

#ifndef MIDI_PARSER_READNUMBER_H
#define MIDI_PARSER_READNUMBER_H


#include <cstdio>
#include <cstdint>
#include "Options.h"

/**
 * Reads the 16-bit number from file. Accounts for system endianness.
 * @param f File pointer
 * @return Number read
 */
uint16_t read16(FILE* f);
/**
 * Reads the 32-bit number from file. Accounts for system endianness.
 * @param f File pointer
 * @return Number read
 */
uint32_t read32(FILE* f);

#endif //MIDI_PARSER_READNUMBER_H
