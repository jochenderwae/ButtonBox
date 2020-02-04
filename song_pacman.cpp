#include <Arduino.h>
#include <avr/pgmspace.h>
#include "MusicPlayer.h"

// taken from https://github.com/robsoncouto/arduino-songs/

extern const PROGMEM int pacman[] = {
  
  105, // tempo
  
  NOTE_B4,  SIXT,     NOTE_B5,  SIXT,     NOTE_FS5, SIXT, NOTE_DS5, SIXT, //1
  NOTE_B5,  THRT,     NOTE_FS5, SIXT_DOT, NOTE_DS5, EIGT, NOTE_C5,  SIXT,
  NOTE_C6,  SIXT,     NOTE_G6,  SIXT,     NOTE_E6,  SIXT, NOTE_C6,  THRT, NOTE_G6,  SIXT_DOT, NOTE_E6, EIGT,

  NOTE_B4,  SIXT,     NOTE_B5,  SIXT,     NOTE_FS5, SIXT, NOTE_DS5, SIXT, NOTE_B5,  THRT,  //2
  NOTE_FS5, SIXT_DOT, NOTE_DS5, EIGT,     NOTE_DS5, THRT, NOTE_E5,  THRT, NOTE_F5,  THRT,
  NOTE_F5,  THRT,     NOTE_FS5, THRT,     NOTE_G5,  THRT, NOTE_G5,  THRT, NOTE_GS5, THRT,     NOTE_A5, SIXT, NOTE_B5, EIGT,
  NOTE_END, NOTE_END, NOTE_END, NOTE_END, NOTE_END, NOTE_END
};
