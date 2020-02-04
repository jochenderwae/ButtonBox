#include <Arduino.h>
#include <avr/pgmspace.h>
#include "MusicPlayer.h"

// taken from https://github.com/robsoncouto/arduino-songs/

extern const PROGMEM int zeldaLullaby[] = {
  // Zelda's Lullaby - The Legend of Zelda Ocarina of Time. 
  // Score available at https://musescore.com/user/12754451/scores/2762776

  108, // tempo
  
  //B-flat major Bb Eb
  NOTE_E4, HALF,     NOTE_G4, QART,
  NOTE_D4, HALF,     NOTE_C4, EIGT, NOTE_D4, EIGT, 
  NOTE_E4, HALF,     NOTE_G4, QART,
  NOTE_D4, HALF_DOT,
  NOTE_E4, HALF,     NOTE_G4, QART,
  NOTE_D5, HALF,     NOTE_C5, QART,
  NOTE_G4, HALF,     NOTE_F4, EIGT, NOTE_E4, EIGT, 
  NOTE_D4, HALF_DOT,
  NOTE_E4, HALF,     NOTE_G4, QART,
  NOTE_D4, HALF,     NOTE_C4, EIGT, NOTE_D4, EIGT, 
  NOTE_E4, HALF,     NOTE_G4, QART,
  NOTE_D4, HALF_DOT,
  NOTE_E4, HALF,     NOTE_G4, QART,

  NOTE_D5, HALF,     NOTE_C5, QART,
  NOTE_G4, HALF,     NOTE_F4, EIGT, NOTE_E4, EIGT, 
  NOTE_F4, EIGT,     NOTE_E4, EIGT, NOTE_C4, HALF,
  NOTE_F4, HALF,     NOTE_E4, EIGT, NOTE_D4, EIGT, 
  NOTE_E4, EIGT,     NOTE_D4, EIGT, NOTE_A3, HALF,
  NOTE_G4, HALF,     NOTE_F4, EIGT, NOTE_E4, EIGT, 
  NOTE_F4, EIGT,     NOTE_E4, EIGT, NOTE_C4, QART, NOTE_F4, QART,
  NOTE_C5, HALF_DOT, 
  NOTE_END
};
