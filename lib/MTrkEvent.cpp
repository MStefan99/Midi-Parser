//
// Created by MStefan99 on 4.8.20.
//

#include "MTrkEvent.h"


MTrkEvent::MTrkEvent(const char* filePath, long addr) :
		Event(filePath, addr + VLQ(filePath,addr).getLength()),
		deltaTime(VLQ(filePath, addr)) {}
