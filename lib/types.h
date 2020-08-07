//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_TYPES_H
#define MIDI_PARSER_TYPES_H

/**
 * \brief Contains definitions for different types, formats and statuses
 */
struct MidiType {
	/**
	 * \brief Formats of the Midi files
	 *
	 * - In accordance with MIDI 1.0 specification
	 */
	typedef enum {
		SingleTrack = 0,  /**< Files which only contain a single track */
		SimTracks = 1,  /**< Files which contain multiple tracks played simultaneously */
		IndTracks = 2  /**< Files which contain multiple tracks played independently */
	} FileFormat;

	/**
	 * \brief Types of the Midi events
	 */
	typedef enum {
		MidiEvent = 0,  /**< Midi events */
		SysExEvent = 1,  /**< System exclusive events */
		MetaEvent = 2  /**< Meta events */
	} EventType;

	/**
	 * \brief Statuses of the Midi messages
	 *
	 * - In accordance with MIDI 1.0 specification
	 */
	typedef enum {
		NoteOff = 0x80,  /**< Note Off event */
		NoteOn = 0x90,  /**< Note On event (considered Note Off if velocity is 0) */
		PolyphonicKeyPressure = 0xA0,  /**< Key pressure event after note was pressed (Aftertouch) */
		ControlChange = 0xB0,  /**< Control change event */
		ProgramChange = 0xC0,  /**< Program change event */
		ChannelPressure = 0xD0,  /**< Channel aftertouch event */
		PitchBend = 0xE0  /**< Pitch wheel event */
	} MidiMessageStatus;

	/**
	 * \brief Statuses of the System Exclusive Messages
	 *
	 * - In accordance with MIDI 1.0 specification
	 */
	typedef enum {
		SOX = 0xF0,  /**< Start of System Exclusive event */
		EOX = 0xF7  /**< End of System Exclusive event */
	} SysExMessageStatus;

	/**
	 * \brief Statuses of the Meta events
	 *
	 * - In accordance with MIDI 1.0 specification
	 */
	typedef enum {
		SequenceNumber = 0x00,  /**< Sequence number event */
		TextEvent = 0x01,  /**< Text event */
		CopyrightNotice = 0x02,  /**< Copyright notice event */
		SequenceName = 0x03,  /**< Sequence name event */
		InstrumentName = 0x04,  /**< Instrument name event */
		Lyric = 0x05,  /**< Lyric event */
		Marker = 0x06,  /**< Marker event */
		CuePoint = 0x07,  /**< Cue point event */
		MidiChannelPrefix = 0x20,  /**< Midi channel prefix event */
		EndOfTrack = 0x2F,  /**< End of track event */
		SetTempo = 0x51,  /**< Set tempo event */
		SMTPEOffset = 0x54,  /**< SMTPE offset event */
		TimeSignature = 0x58,  /**< Time signature event */
		KeySignature = 0x59,  /**< Key signature event */
		SequencerSpecific = 0x7F  /**< Sequencer-specific event */
	} MetaMessageStatus;
};

#endif //MIDI_PARSER_TYPES_H
