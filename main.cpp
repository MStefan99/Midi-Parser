#include "MidiFile.h"


char PATH[] = "./res/reference.mid";


int main() {
	MidiFile f {PATH};

	printf("File read.");
	return 0;
}



