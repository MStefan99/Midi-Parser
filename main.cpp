#include "MidiFile.h"


char PATH[] = "./res/sample.mid";


int main() {
	MidiFile f {PATH};

	printf("File read.");
	return 0;
}



