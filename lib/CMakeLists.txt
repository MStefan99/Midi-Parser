add_library(libParser)
target_sources(libParser PRIVATE
		ReadNumber.cpp
		VLQ.cpp
		Event.cpp
		MidiEvent.cpp
		SysExEvent.cpp
		MetaEvent.cpp
		MTrkEvent.cpp
		BaseChunk.cpp
		HeaderChunk.cpp
		TrackChunk.cpp
		Midi.cpp
		)

target_include_directories(libParser PUBLIC .)

