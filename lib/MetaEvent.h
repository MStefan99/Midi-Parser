//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_METAEVENT_H
#define MIDI_PARSER_METAEVENT_H


#include <cstdio>
#include <cstdint>
#include "types.h"
#include "Event.h"

/**
 * \class MetaEvent
 * \brief Contains data of the meta event
 *
 * Contains data of the Midi meta event and provides methods to retrieve it
 */
class MetaEvent: public Event {
public:
	/**
	 * Default constructor
	 */
	MetaEvent() = default;
	/**
	 * Reads the Midi file and constructs the event object
	 * @param filePath Path to the Midi file
	 * @param addr Address of the event in bytes
	 */
	MetaEvent(const char* filePath, long addr);
	/**
	 * Destroys the MetaEvent object
	 */
	~MetaEvent() override;
	/**
	 * Clones the event object
	 * @return Pointer to the cloned event object
	 */
	[[nodiscard]] MetaEvent* clone() const override;

	/**
	 * Returns the event type
	 * @return Event type. Always equals to MidiType::EventType::MetaEvent
	 */
	[[nodiscard]] MidiType::EventType getType() const override;
	/**
	 * Returns the event status
	 * @return The status of the event
	 */
	[[nodiscard]] MidiType::MetaMessageStatus getStatus() const;
	/**
	 * Returns the event data length
	 * @return The length of the event data
	 */
	[[nodiscard]] uint8_t getLength() const;
	/**
	 * Returns the event data
	 * @return Pointer to event data. Should not be read past its length
	 */
	[[nodiscard]] uint8_t* getData() const;

protected:
	uint8_t code {};
	uint8_t status {};
	uint8_t length {};
	uint8_t* data {};
};

#endif //MIDI_PARSER_METAEVENT_H
