#include <Arduino.h>
#include <avr/pgmspace.h>
#include "MusicPlayer.h"

// taken from https://github.com/robsoncouto/arduino-songs/

extern const PROGMEM int greenHillZone[] = {
  // Gren Hill Zone - Sonic the Hedgehog
  // Score available at https://musescore.com/user/248346/scores/461661
  // Theme by Masato Nakamura, arranged by Teddy Mason

  140, // tempo
  
  REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
  NOTE_E4,-1,
  REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

  REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
  REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,-1, //end 1

  //repeats from 1

  REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
  NOTE_E4,-1,
  REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

  REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
  REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,8, //end 2
  NOTE_E4,-2, NOTE_A4,8, NOTE_CS5,8, 
  NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8, NOTE_A5,-4,
  NOTE_END
};