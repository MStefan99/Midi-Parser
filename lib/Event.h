//
// Created by MStefan99 on 4.8.20.
//

#ifndef MIDI_PARSER_EVENT_H
#define MIDI_PARSER_EVENT_H


#include <cstdint>
#include <cstdio>
#include "types.h"

/**
 * \class Event
 * \brief A base class for Midi events
 *
 * A virtual class all event classes are derived from
 */
class Event {
public:
	/**
	 * Destroys the Event object
	 */
	virtual ~Event() = default;
	/**
	 * Clones the event
	 * @return A pointer to the cloned Event object
	 */
	[[nodiscard]] virtual Event* clone() const = 0;
	/**
	 * Returns the type of the event
	 * @return Event type, should be different for every derived class
	 */
	[[nodiscard]] virtual MidiType::EventType getType() const = 0;

	/**
	 * Returns the length of the Event
	 * @return The length of the Event in bytes
	 */
	[[nodiscard]] uint8_t getByteLength() const;

protected:
	uint8_t byteLength {};
};

#endif //MIDI_PARSER_EVENT_H
