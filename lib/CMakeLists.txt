add_library(libParser)
target_sources(libParser PRIVATE
		ReadNumber.cpp
		VLQ.cpp
		Event.cpp
		MTrkEvent.cpp
		BaseChunk.cpp
		HeaderChunk.cpp
		TrackChunk.cpp
		MidiFile.cpp
		)

target_include_directories(libParser PUBLIC .)

