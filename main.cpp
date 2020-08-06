#include "Midi.h"
#include <iostream>


using namespace std;

char PATH[] = "./res/reference.mid";


int main() {
	Midi f {PATH};

	auto& header = f.getHeader();
	auto& tracks = f.getTracks();

	cout << "File read" << endl;
	cout << "File contents:" << endl;
	cout << "	Header:" << endl;
	cout << "		File format: " << (int)header.getFormat() <<
		 "\n		Number of tracks: " << header.getNTracks() <<
		 "\n		Time division: " << header.getDivision() << endl;

	for (const auto& track : tracks) {
		cout << "	Track events:" << endl;
		auto& events = track.getEvents();

		for (const auto& trackEvent : events) {
			auto* event = trackEvent.getEvent();
			uint8_t* data;

			switch (event->getType()) {
				case MidiType::MidiEvent:
					cout << "		Midi event:" << endl;
					cout << "			Status: 0x" << hex
						 << ((MidiEvent*)event)->getStatus() << endl;
					cout << "			Data: 0x"
						 << ((MidiEvent*)event)->getData() << dec << endl;
					break;
				case MidiType::SysExEvent:
					cout << "\t\tSystem exclusive event:" << endl;
					cout << "\t\t\tStatus: 0x" << hex
						 << ((MetaEvent*)event)->getStatus() << endl;
					cout << "\t\t\tData: 0x";

					data = ((MetaEvent*)event)->getData();
					for (int i {0}; i < ((MetaEvent*)event)->getLength(); ++i) {
						cout << (int)data[i];
					}
					cout << endl;
					break;
				case MidiType::MetaEvent:
					cout << "\t\tMeta event:" << endl;
					cout << "\t\t\tStatus: 0x" << hex
						 << ((MetaEvent*)event)->getStatus() << endl;
					cout << "\t\t\tData: 0x";

					data = ((MetaEvent*)event)->getData();
					for (int i {0}; i < ((MetaEvent*)event)->getLength(); ++i) {
						cout << (int)data[i];
					}
					if (!((MetaEvent*)event)->getLength()) {
						cout << "0";
					}
					cout << endl;
					break;
			}
		}
	}

	return 0;
}



