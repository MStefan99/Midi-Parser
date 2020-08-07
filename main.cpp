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

			if (event->getType() == MidiType::EventType::MidiEvent) {
				auto* midiEvent = (MidiEvent*)event;

				cout << "		Midi event:" << endl;
				auto status = midiEvent->getStatus();

				if (status == MidiType::MidiMessageStatus::NoteOn) {
					cout << "\t\t\t" << "Note " << (midiEvent->getVelocity()? "on " : "off ")
						 << (int)midiEvent->getNote()
						 << " on channel " << (int)midiEvent->getChannel() << endl;
				} else if (status == MidiType::MidiMessageStatus::NoteOff) {
					cout << "\t\t\t" << "Note off "
						 << (int)midiEvent->getNote()
						 << " on channel " << (int)midiEvent->getChannel() << endl;
				} else {
					cout << "\t\t\tStatus: 0x" << hex << (int)midiEvent->getStatus() << endl
						 << "\t\t\tData: 0x" << midiEvent->getData() << dec << endl;
				}
			} else if (event->getType() == MidiType::EventType::SysExEvent) {
				cout << "\t\tSystem exclusive event:" << endl
					 << "\t\t\tStatus: 0x" << hex
					 << ((MetaEvent*)event)->getStatus() << endl
					 << "\t\t\tData: 0x";

				data = ((MetaEvent*)event)->getData();
				for (int i {0}; i < ((MetaEvent*)event)->getLength(); ++i) {
					cout << (int)data[i];
				}
				cout << dec << endl;
			} else {  // event->getType() == MidiType::EventType::MetaEvent
				cout << "\t\tMeta event:" << endl
					 << "\t\t\tStatus: 0x" << hex
					 << ((MetaEvent*)event)->getStatus() << endl
					 << "\t\t\tData: 0x";

				data = ((MetaEvent*)event)->getData();
				for (int i {0}; i < ((MetaEvent*)event)->getLength(); ++i) {
					cout << (int)data[i];
				}
				if (!((MetaEvent*)event)->getLength()) {
					cout << "0";
				}
				cout << dec << endl;
			}

			cout << "\t\t\tLength: " << trackEvent.getDeltaTime().getData() << endl;
		}
	}

	return 0;
}



