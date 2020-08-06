//
// Created by MStefan99 on 4.8.20.
//

#include "TrackChunk.h"


TrackChunk::TrackChunk(const char* filePath, long addr):
		BaseChunk(filePath, addr) {
	addr += 8;
	long bytesRead {0};

	while (bytesRead < length) {
		MTrkEvent event {filePath, addr};
		events.push_back(event);
		addr += event.getByteLength();
		bytesRead += event.getByteLength();
	}
}
