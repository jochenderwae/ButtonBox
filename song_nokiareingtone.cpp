#include <Arduino.h>
#include <avr/pgmspace.h>
#include "MusicPlayer.h"

// taken from https://github.com/robsoncouto/arduino-songs/

extern const PROGMEM int nokiaRingtone[] = {
  // Nokia Ringtone 
  // Score available at https://musescore.com/user/29944637/scores/5266155

  180, // tempo
  
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2, 
  NOTE_END
};
