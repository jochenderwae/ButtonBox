#include <Arduino.h>
#include <avr/pgmspace.h>
#include "MusicPlayer.h"

// taken from https://github.com/robsoncouto/arduino-songs/

extern const PROGMEM int keyboardCat[] = {
  // Keyboard cat
  // Score available at https://musescore.com/user/142788/scores/147371

  160, // tempo
  
  REST,1,
	REST,1,
	NOTE_C4,4, NOTE_E4,4, NOTE_G4,4, NOTE_E4,4, 
	NOTE_C4,4, NOTE_E4,8, NOTE_G4,-4, NOTE_E4,4,
	NOTE_A3,4, NOTE_C4,4, NOTE_E4,4, NOTE_C4,4,
	NOTE_A3,4, NOTE_C4,8, NOTE_E4,-4, NOTE_C4,4,
	NOTE_G3,4, NOTE_B3,4, NOTE_D4,4, NOTE_B3,4,
	NOTE_G3,4, NOTE_B3,8, NOTE_D4,-4, NOTE_B3,4,

	NOTE_G3,4, NOTE_G3,8, NOTE_G3,-4, NOTE_G3,8, NOTE_G3,4, 
	NOTE_G3,4, NOTE_G3,4, NOTE_G3,8, NOTE_G3,4,
	NOTE_C4,4, NOTE_E4,4, NOTE_G4,4, NOTE_E4,4, 
	NOTE_C4,4, NOTE_E4,8, NOTE_G4,-4, NOTE_E4,4,
	NOTE_A3,4, NOTE_C4,4, NOTE_E4,4, NOTE_C4,4,
	NOTE_A3,4, NOTE_C4,8, NOTE_E4,-4, NOTE_C4,4,
	NOTE_G3,4, NOTE_B3,4, NOTE_D4,4, NOTE_B3,4,
	NOTE_G3,4, NOTE_B3,8, NOTE_D4,-4, NOTE_B3,4,

	NOTE_G3,-1, 
  NOTE_END
};
