//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_MTRKEVENT_H
#define MIDI_PARSER_MTRKEVENT_H


#include <cstdint>
#include <cstdio>
#include "VLQ.h"
#include "MidiEvent.h"
#include "SysExEvent.h"
#include "MetaEvent.h"
#include "ReadNumber.h"

/**
 * \class MTrkEvent
 * \brief Stores the Midi event along with delta-time
 */
class MTrkEvent {
public:
	/**
	 * Reads Midi file and constructs an MTrkEvent object
	 * @param filePath
	 * @param addr
	 */
	MTrkEvent(const char* filePath, long addr);
	/**
	 * Copies the MTrkEvent object
	 * @param event The MTrkEvent to copy
	 */
	MTrkEvent(const MTrkEvent& event);
	/**
	 * Destroys the MTrkEvent object
	 */
	~MTrkEvent();

	/**
	 * Returns the MTrkEvent delta-time
	 * @return Delta-time of the MTrkEvent
	 */
	[[nodiscard]] const VLQ& getDeltaTime() const;
	/**
	 * Returns the Event of the MTrkEvent
	 * @return Pointer to the Event object
	 */
	[[nodiscard]] const Event* getEvent() const;
	/**
	 * Returns the length of MTrkEvent
	 * @return Length of MTrkEvent in bytes
	 */
	[[nodiscard]] long getByteLength() const;

protected:
	VLQ deltaTime {};
	Event* event {};
	long byteLength {};
};

#endif //MIDI_PARSER_MTRKEVENT_H
