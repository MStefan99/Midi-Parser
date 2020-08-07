//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_MIDIEVENT_H
#define MIDI_PARSER_MIDIEVENT_H


#include <cstdint>
#include <cstdio>
#include "types.h"
#include "Event.h"

/**
 * \class MidiEvent
 * \brief Contains data of the Midi event
 *
 * Contains the data of the Midi event and provides the methods to retrieve it
 */
class MidiEvent: public Event {
public:
	/**
	 * Reads the Midi file and constructs the event object
	 * @param filePath Path to the Midi file
	 * @param addr Address of the event in bytes
	 */
	MidiEvent(const char* filePath, long addr);
	/**
	 * Destroys the event object
	 */
	~MidiEvent() override = default;
	/**
	 * Clones the event object
	 * @return Pointer to the cloned event
	 */
	[[nodiscard]] Event * clone() const override;

	/**
	 * Returns the type of the event
	 * @return Event type. Always equals to MidiType::EventType::MidiEvent
	 */
	[[nodiscard]] MidiType::EventType getType() const override;
	/**
	 * Returns the event status
	 * @return The status of the event
	 */
	[[nodiscard]] MidiType::MidiMessageStatus getStatus() const;
	/**
	 * Returns the channel of the message
	 * @return Channel number
	 */
	[[nodiscard]] uint8_t getChannel() const;
	/**
	 * Returns note number for Note on/off events
	 * @return Number of the note for note events, otherwise 0
	 */
	[[nodiscard]] uint8_t getNote() const;
	/**
	 * Returns note velocity for Note on/off events
	 * @return Velocity of the note for note events, otherwise 0. Velocity of 0 means Note off
	 */
	[[nodiscard]] uint8_t getVelocity() const;
	/**
	 * Returns event data
	 * @return Data of the event
	 */
	[[nodiscard]] uint16_t getData() const;

protected:
	static uint8_t lastStatus;

	uint8_t status {};
	uint16_t data {};
};

#endif //MIDI_PARSER_MIDIEVENT_H
