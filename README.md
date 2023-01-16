# Midi Parser

*Midi Parser is a tiny C++ library made to simplify reading binary Midi files.*
___

![Maintenance](https://img.shields.io/maintenance/no/2020?style=flat-square)


## Compatibility
Midi Parser is written in C++ and uses `<cstdio>` library for reading files so any device 
that supports those will be able to run Midi Parser. The parser may optionally use STL if your device supports it.


## Installation
1. Navigate to the [releases][releases] page and download the archive for the latest release.
1. Extract the files from archive into your project directory. *(Note: source archive includes
both source files and headers. Depending on your environment, you may need to place them 
in different directories.)*
1. Open `Options.h` file and set the options there:
    - Set the `USE_BIG_ENDIAN` macro to `true` if your system is big-endian.
    - Set the `USE_STL` macro to `true` if you can use STL.
1. Include library into your code: `#include "Midi.h"`


## Usage
- Instantiate the `Midi` object as follows: `Midi midiFile {"path_to_file.mid"};`.
- You can find a simple program using Midi Parser in the `main.cpp` file.
- For the full library reference, please check the [documentation][doc].


[releases]: https://github.com/MStefan99/Midi-Parser/releases
[doc]: http://midi-parser.mstefan99.com/html/class_midi.html
