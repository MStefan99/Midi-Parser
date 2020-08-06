//
// Created by MStefan99 on 6.8.20.
//

#ifndef MIDI_PARSER_TYPES_H
#define MIDI_PARSER_TYPES_H

struct MidiType {
	typedef enum {  // In accordance with MIDI 1.0 specification
		SingleTrack = 0,  // Files which only contain a single track
		SimTracks = 1,  // Files which contain multiple tracks played simultaneously
		IndTracks = 2  // Files which contain multiple tracks played independently
	} FileFormat;

	typedef enum {
		MidiEvent = 0,  // Midi events
		SysExEvent = 1,  // System exclusive events
		MetaEvent = 2  // Meta events
	} EventType;

	typedef enum {  // In accordance with MIDI 1.0 specification
		NoteOff = 0x80,
		NoteOn = 0x90,
		PolyphonicKeyPressure = 0xA0,
		ControlChange = 0xB0,
		ProgramChange = 0xC0,
		ChannelPressure = 0xD0,
		PitchBend = 0xE0
	} MidiMessageStatus;

	typedef enum {  // In accordance with MIDI 1.0 specification
		SOX = 0xF0,
		EOX = 0xF7
	} SysExMessageStatus;

	typedef enum {  // In accordance with MIDI 1.0 specification
		SequenceNumber = 0x00,
		TextEvent = 0x01,
		CopyrightNotice = 0x02,
		SequenceName = 0x03,
		InstrumentName = 0x04,
		Lyric = 0x05,
		Marker = 0x06,
		CuePoint = 0x07,
		MidiChannelPrefix = 0x20,
		EndOfTrack = 0x2F,
		SetTempo = 0x51,
		SMTPEOffset = 0x54,
		TimeSignature = 0x58,
		KeySignature = 0x59,
		SequencerSpecific = 0x7F
	} MetaMessageStatus;
};

#endif //MIDI_PARSER_TYPES_H
