//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_SYSEXEVENT_H
#define MIDI_PARSER_SYSEXEVENT_H


#include <cstdio>
#include <cstdint>
#include "types.h"
#include "Event.h"

/**
 * \class SysExEvent
 * \brief Contains data of the System Exclusive event
 *
 * Contains the data of the System Exclusive event and provides the methods to retrieve it
 */
class SysExEvent: public Event {
public:
	/**
	 * Default constructor
	 */
	SysExEvent() = default;
	/**
	 * Reads the Midi file and constructs the event object
	 * @param filePath File path to read the data from
	 * @param addr Address of the event in bytes
	 */
	SysExEvent(const char* filePath, long addr);
	/**
	 * Destroys the event object
	 */
	~SysExEvent() override;
	/**
	 * Clones the event object
	 * @return Pointer to the cloned event object
	 */
	[[nodiscard]] Event* clone() const override;

	/**
	 * Returns the type of the event
	 * @return Event type. Always equals to MidiType::EventType::SysExEvent
	 */
	[[nodiscard]] MidiType::EventType getType() const override;
	/**
	 * Returns the event status
	 * @return Status of the event
	 */
	[[nodiscard]] MidiType::SysExMessageStatus getStatus() const;
	/**
	 * Returns event data length
	 * @return Length of the event data in bytes
	 */
	[[nodiscard]] uint8_t getLength() const;
	/**
	 * Returns the event data
	 * @return Pointer to the event data. Should not be read past its length
	 */
	[[nodiscard]] uint8_t* getData() const;

protected:
	uint8_t status {};
	uint8_t length {};
	uint8_t* data {};
};

#endif //MIDI_PARSER_SYSEXEVENT_H
