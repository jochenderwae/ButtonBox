#include <Arduino.h>
#include <avr/pgmspace.h>
#include "MusicPlayer.h"

// taken from https://github.com/robsoncouto/arduino-songs/

extern const PROGMEM int bloodytears[] = {
  // Bloody Tears, from Castlevania II
  // Arranged by Bobby Lee. THe flute part was used 
  // https://musescore.com/user/263171/scores/883296

  144, // tempo
  
  //B-flat major Bb Eb
  REST,     QART,      NOTE_G5,  QART,
  NOTE_A5,  QART,      NOTE_AS5, QART,
  NOTE_A5,  QART,      NOTE_F5,  QART,
  NOTE_A5,  QART,      NOTE_G5,  QART,
  REST,     QART,      NOTE_G5,  QART,
  NOTE_A5,  QART,      NOTE_AS5, QART,
  NOTE_C6,  QART,      NOTE_AS5, QART,

  NOTE_A5,  QART,      NOTE_G5,  QART, //8
  REST,     QART,      NOTE_G5,  QART,
  NOTE_A5,  QART,      NOTE_AS5, QART,
  NOTE_A5,  QART,      NOTE_F5,  QART,
  NOTE_A5,  QART,      NOTE_G5,  QART,
  NOTE_D6,  QART,      REST,     EIGT,      NOTE_C6, EIGT,
  REST,     QART,      NOTE_AS5, QART,

  NOTE_A5,  QART,      NOTE_AS5, EIGT,      NOTE_C6,  EIGT, //15
  NOTE_F6,  EIGT,      REST,     EIGT,      REST,     QART,
  NOTE_G5,  SIXT,      NOTE_D5,  SIXT,      NOTE_D6,  SIXT,      NOTE_D5, SIXT,      NOTE_C6, SIXT,     NOTE_D5, SIXT,     NOTE_AS5, SIXT,     NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,      NOTE_A5, SIXT,     NOTE_D5, SIXT,     NOTE_G5,  SIXT,     NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,      NOTE_C6, SIXT,     NOTE_D5, SIXT,     NOTE_AS5, SIXT,     NOTE_D5, SIXT,

  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_F5,  SIXT,      NOTE_D5, SIXT,      NOTE_A5, SIXT,     NOTE_D5, SIXT,     NOTE_G5,  SIXT,     NOTE_D5, SIXT, //20
  NOTE_G5,  SIXT,      NOTE_D5,  SIXT,      NOTE_D6,  SIXT,      NOTE_D5, SIXT,      NOTE_C6, SIXT,     NOTE_D5, SIXT,     NOTE_AS5, SIXT,     NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,      NOTE_A5, SIXT,     NOTE_D5, SIXT,     NOTE_AS5, SIXT,     NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,      NOTE_C6, SIXT,     NOTE_D5, SIXT,     NOTE_AS5, SIXT,     NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_F5,  SIXT,      NOTE_D5, SIXT,      NOTE_A5, SIXT,     NOTE_D5, SIXT,     NOTE_G5,  SIXT,     NOTE_D5, SIXT,

  NOTE_G5,  SIXT,      NOTE_D5,  SIXT,      NOTE_D6,  SIXT,      NOTE_D5, SIXT,      NOTE_C6, SIXT,     NOTE_D5, SIXT,     NOTE_AS5, SIXT,     NOTE_D5, SIXT, //25
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,      NOTE_A5, SIXT,     NOTE_D5, SIXT,     NOTE_G5,  SIXT,     NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,      NOTE_C6, SIXT,     NOTE_D5, SIXT,     NOTE_AS5, SIXT,     NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_F5,  SIXT,      NOTE_D5, SIXT,      NOTE_A5, SIXT,     NOTE_D5, SIXT,     NOTE_G5,  SIXT,     NOTE_D5, SIXT,
  NOTE_AS5, SIXT,      NOTE_D5,  SIXT,      NOTE_D6,  SIXT,      NOTE_D5, SIXT,      NOTE_C6, SIXT,     NOTE_D5, SIXT,     NOTE_AS5, SIXT,     NOTE_D5, SIXT,

  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,      NOTE_A5, SIXT,     NOTE_D5, SIXT,     NOTE_G5,  SIXT,     NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,      NOTE_C6, SIXT,     NOTE_D5, SIXT,     NOTE_AS5, SIXT,     NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_F5,  SIXT,      NOTE_D5, SIXT,      NOTE_A5, SIXT,     NOTE_D5, SIXT,     NOTE_G5,  SIXT,     NOTE_D5, SIXT,
  NOTE_C6,  SIXT,      NOTE_C6,  SIXT,      NOTE_F6,  SIXT,      NOTE_D6, EIGT,      REST,    SIXT,     REST,    EIGT,
  REST,     QART,      NOTE_C6,  SIXT,      NOTE_AS5, SIXT,

  NOTE_C6,  EIGT_DOT,  NOTE_F6,  EIGT_DOT,  NOTE_D6,  QART_DOT, //35
  NOTE_C6,  EIGT,      NOTE_AS5, EIGT,
  NOTE_C6,  EIGT,      NOTE_F6,  SIXT,      NOTE_D6,  EIGT,      REST,    SIXT,      REST, EIGT,
  REST,     QART,      NOTE_C6,  EIGT,      NOTE_D6,  EIGT,
  NOTE_DS6, EIGT_DOT,  NOTE_F6,  EIGT_DOT,

  NOTE_D6,  EIGT_DOT,  REST,     SIXT,      NOTE_DS6, EIGT,      REST,    EIGT, //40
  NOTE_C6,  EIGT,      NOTE_F6,  SIXT,      NOTE_D6,  EIGT,      REST,    SIXT,      REST, EIGT,
  REST,     QART,      NOTE_C6,  EIGT,      NOTE_AS5, EIGT,
  NOTE_C6,  EIGT_DOT,  NOTE_F6,  EIGT_DOT,  NOTE_D6,  QART_DOT,
  NOTE_C6,  EIGT,      NOTE_AS5, EIGT,

  NOTE_C6,  EIGT,      NOTE_F6,  SIXT,      NOTE_D6,  EIGT,      REST,    SIXT,      REST, EIGT, //45
  REST,     QART,      NOTE_C6,  EIGT,      NOTE_D6,  EIGT,
  NOTE_DS6, EIGT_DOT,  NOTE_F6,  EIGT_DOT,
  NOTE_D5,  EIGT,      NOTE_FS5, EIGT,      NOTE_F5,  EIGT,      NOTE_A5, EIGT,
  NOTE_A5,  EIGT_DOT,  NOTE_G5,  QART_DOT,

  NOTE_A5,  EIGT_DOT,  NOTE_G5,  QART_DOT, //50
  NOTE_A5,  EIGT_DOT,  NOTE_G5,  QART_DOT,
  NOTE_AS5, EIGT,      NOTE_A5,  EIGT,      NOTE_G5,  EIGT,      NOTE_F5, EIGT,
  NOTE_A5,  EIGT_DOT,  NOTE_G5,  EIGT_DOT,  NOTE_D5,  EIGT,
  NOTE_A5,  EIGT_DOT,  NOTE_G5,  EIGT_DOT,  NOTE_D5,  EIGT,
  NOTE_A5,  EIGT_DOT,  NOTE_G5,  EIGT_DOT,  NOTE_D5,  EIGT,

  NOTE_AS5, QART,      NOTE_C6,  QART,      NOTE_A5,  QART,      NOTE_AS5, QART,
  NOTE_G5,  SIXT,      NOTE_D5,  SIXT,      NOTE_D6,  SIXT,      NOTE_D5,  SIXT,      NOTE_C6, SIXT,       NOTE_D5, SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,//56 //r
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5,  SIXT,      NOTE_A5, SIXT,       NOTE_D5, SIXT,      NOTE_G5,  SIXT,      NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5,  SIXT,      NOTE_C6, SIXT,       NOTE_D5, SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_F5,  SIXT,      NOTE_D5,  SIXT,      NOTE_A5, SIXT,       NOTE_D5, SIXT,      NOTE_G5,  SIXT,      NOTE_D5, SIXT,

  NOTE_G5,  SIXT,      NOTE_D5,  SIXT,      NOTE_D6,  SIXT,      NOTE_D5, SIXT,       NOTE_C6, SIXT,       NOTE_D5, SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,//61
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,       NOTE_A5, SIXT,       NOTE_D5, SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,       NOTE_C6, SIXT,       NOTE_D5, SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_F5,  SIXT,      NOTE_D5, SIXT,       NOTE_A5, SIXT,       NOTE_D5, SIXT,      NOTE_G5,  SIXT,      NOTE_D5, SIXT,
  NOTE_G5,  SIXT,      NOTE_D5,  SIXT,      NOTE_D6,  SIXT,      NOTE_D5, SIXT,       NOTE_C6, SIXT,       NOTE_D5, SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,

  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,       NOTE_A5, SIXT,       NOTE_D5, SIXT,      NOTE_G5,  SIXT,      NOTE_D5, SIXT,//66
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,       NOTE_C6, SIXT,       NOTE_D5, SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_F5,  SIXT,      NOTE_D5, SIXT,       NOTE_A5, SIXT,       NOTE_D5, SIXT,      NOTE_G5,  SIXT,      NOTE_D5, SIXT,
  NOTE_AS5, SIXT,      NOTE_D5,  SIXT,      NOTE_D6,  SIXT,      NOTE_D5, SIXT,       NOTE_C6, SIXT,       NOTE_D5, SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,       NOTE_A5, SIXT,       NOTE_D5, SIXT,      NOTE_G5,  SIXT,      NOTE_D5, SIXT,

  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_AS5, SIXT,      NOTE_D5, SIXT,       NOTE_C6, SIXT,       NOTE_D5, SIXT,      NOTE_AS5, SIXT,      NOTE_D5,  SIXT,//71 //
  NOTE_A5,  SIXT,      NOTE_D5,  SIXT,      NOTE_F5,  SIXT,      NOTE_D5, SIXT,       NOTE_A5, EIGT,       NOTE_G5, THRT,      NOTE_A5,  THRT,      NOTE_AS5, THRT,      NOTE_C6, THRT,
  NOTE_D6,  SIXT,      NOTE_G5,  SIXT,      NOTE_AS5, SIXT,      NOTE_G5, SIXT,       NOTE_C6, SIXT,       NOTE_G5, SIXT,      NOTE_D6,  SIXT,      NOTE_G5,  SIXT,
  NOTE_C6,  SIXT,      NOTE_G5,  SIXT,      NOTE_A5,  SIXT,      NOTE_G5, SIXT,       NOTE_F6, SIXT,       NOTE_G5, SIXT,      NOTE_D6,  SIXT,      NOTE_DS5, SIXT,
  NOTE_D6,  QART,      REST,     QART,

  NOTE_C5,  EIGT,      REST,     EIGT,      NOTE_A4,  SIXT_DOT,  NOTE_AS4, SIXT_DOT,  NOTE_C5, SIXT, //76
  NOTE_D6,  SIXT,      NOTE_G4,  SIXT,      NOTE_AS4, SIXT,      NOTE_G4,  SIXT,      NOTE_C5, SIXT,       NOTE_G4,  SIXT,      NOTE_D6, SIXT,      NOTE_G4,  SIXT,
  NOTE_C6,  SIXT,      NOTE_F4,  SIXT,      NOTE_A4,  SIXT,      NOTE_F4,  SIXT,      NOTE_F5, SIXT,       NOTE_F4,  SIXT,      NOTE_D6, SIXT,      NOTE_DS4, SIXT,
  NOTE_D6,  SIXT,      REST,     EIGT,      NOTE_E4,  SIXT,      NOTE_F4,  SIXT,
  
  //change of key B Major A# C# D# F# G#
  NOTE_GS4, EIGT,      REST,     EIGT,      NOTE_AS4, EIGT,      REST, EIGT,

  NOTE_DS5, SIXT,      NOTE_GS4, SIXT,      NOTE_B4,  SIXT,      NOTE_GS4, SIXT,      NOTE_CS5, SIXT,      NOTE_GS4, SIXT,      NOTE_DS5, SIXT,      NOTE_GS4, SIXT, //81
  NOTE_CS5, SIXT,      NOTE_FS4, SIXT,      NOTE_AS4, SIXT,      NOTE_FS4, SIXT,      NOTE_FS5, SIXT,      NOTE_FS4, SIXT,      NOTE_DS5, SIXT,      NOTE_E5,  SIXT,
  NOTE_D5,  QART,      REST,     QART,
  NOTE_CS5, EIGT,      REST,     EIGT,      NOTE_AS4, SIXT_DOT,  NOTE_B4,  SIXT_DOT,  NOTE_CS5, SIXT,
  NOTE_DS5, SIXT,      NOTE_GS4, SIXT,      NOTE_B4,  SIXT,      NOTE_GS4, SIXT,      NOTE_CS5, SIXT,      NOTE_GS4, SIXT,      NOTE_DS5, SIXT,      NOTE_GS4, SIXT,
  
  NOTE_CS5, SIXT,      NOTE_FS4, SIXT,      NOTE_AS4, SIXT,      NOTE_FS4, SIXT,      NOTE_FS5, SIXT,      NOTE_FS4, SIXT,      NOTE_DS5, SIXT,      NOTE_E5,  SIXT,
  NOTE_DS5, QART,      REST,     EIGT,      NOTE_DS5, SIXT,      NOTE_E5,  SIXT,
  NOTE_FS5, SIXT,      NOTE_CS5, SIXT,      NOTE_E5,  SIXT,      NOTE_CS4, SIXT,      NOTE_DS5, SIXT,      NOTE_E5,  SIXT,      NOTE_G5,  SIXT,      NOTE_AS5, SIXT,
  NOTE_GS5, SIXT,      NOTE_DS5, SIXT,      NOTE_DS6, SIXT,      NOTE_DS5, SIXT,      NOTE_CS6, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,

  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,      NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_GS5, SIXT,      NOTE_DS5, SIXT, //90
  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,      NOTE_CS6, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,
  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_FS5, SIXT,      NOTE_DS5, SIXT,      NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_GS5, SIXT,      NOTE_DS5, SIXT,
  NOTE_GS5, SIXT,      NOTE_DS5, SIXT,      NOTE_DS6, SIXT,      NOTE_DS5, SIXT,      NOTE_CS6, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,

  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,      NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_GS5, SIXT,      NOTE_DS5, SIXT,//94
  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,      NOTE_CS6, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,
  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_FS5, SIXT,      NOTE_DS5, SIXT,      NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_GS5, SIXT,      NOTE_DS5, SIXT,
  NOTE_GS5, SIXT,      NOTE_DS5, SIXT,      NOTE_DS6, SIXT,      NOTE_DS5, SIXT,      NOTE_CS6, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,

  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,      NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_GS5, SIXT,      NOTE_DS5, SIXT,//98
  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,      NOTE_CS6, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,
  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_FS5, SIXT,      NOTE_DS5, SIXT,      NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_GS5, SIXT,      NOTE_DS5, SIXT,
  NOTE_GS5, SIXT,      NOTE_DS5, SIXT,      NOTE_DS6, SIXT,      NOTE_DS5, SIXT,      NOTE_CS6, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,

  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,      NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_GS5, SIXT,      NOTE_DS5, SIXT,//102
  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,      NOTE_CS6, SIXT,      NOTE_DS5, SIXT,      NOTE_B5,  SIXT,      NOTE_DS5, SIXT,
  NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_FS5, SIXT,      NOTE_DS5, SIXT,      NOTE_AS5, SIXT,      NOTE_DS5, SIXT,      NOTE_GS5, SIXT,      NOTE_DS5, SIXT,
  
  NOTE_CS6, EIGT,      NOTE_FS6, SIXT,      NOTE_DS6, EIGT,      REST,     SIXT,      REST,EIGT, //107
  REST,     QART,      NOTE_CS6, EIGT,      NOTE_B5,  EIGT,
  NOTE_CS6, EIGT_DOT,  NOTE_FS6, EIGT_DOT,  NOTE_DS6, QART_DOT,
  NOTE_CS6, EIGT,      NOTE_B5,  EIGT,
  NOTE_CS6, EIGT,      NOTE_FS6, SIXT,      NOTE_DS6, EIGT,      REST,     SIXT,      REST,EIGT,
  REST,     QART,      NOTE_CS6, EIGT,      NOTE_B5,  EIGT,
  NOTE_E6,  EIGT_DOT,  NOTE_F6,  EIGT_DOT,
  
  NOTE_DS6, EIGT_DOT,  REST,     SIXT,      NOTE_E6,  EIGT,      REST,     SIXT,      REST, SIXT, //112
  NOTE_CS6, EIGT,      NOTE_FS6, SIXT,      NOTE_DS6, EIGT,      REST,     SIXT,      REST, EIGT,
  REST,     QART,      NOTE_CS6, EIGT,      NOTE_B5,  EIGT,
  NOTE_CS6, EIGT_DOT,  NOTE_FS6, EIGT_DOT,  NOTE_DS6, QART_DOT,
  NOTE_CS6, EIGT,      NOTE_B5,  EIGT,
  
  NOTE_CS6, EIGT,      NOTE_FS6, SIXT,      NOTE_DS6, EIGT,      REST,     SIXT,      REST, EIGT, //117
  REST,     QART,      NOTE_CS5, EIGT,      NOTE_DS5, EIGT,
  NOTE_E5,  EIGT_DOT,  NOTE_F5,  EIGT_DOT,
  NOTE_DS5, EIGT,      NOTE_G5,  EIGT,      NOTE_GS5, EIGT,      NOTE_AS5, EIGT,
  NOTE_AS5, EIGT_DOT,  NOTE_GS5, EIGT_DOT,

  NOTE_AS5, EIGT_DOT,  NOTE_GS5, EIGT_DOT,//122
  NOTE_AS5, EIGT_DOT,  NOTE_GS5, EIGT_DOT,
  NOTE_B6,  EIGT,      NOTE_AS5, EIGT,      NOTE_GS5, EIGT,      NOTE_FS5, EIGT,
  NOTE_AS5, EIGT_DOT,  NOTE_GS6, EIGT_DOT,  NOTE_DS5, EIGT,
  NOTE_AS5, EIGT_DOT,  NOTE_GS6, EIGT_DOT,  NOTE_DS5, EIGT,
  NOTE_AS5, EIGT_DOT,  NOTE_GS6, EIGT_DOT,  NOTE_DS5, EIGT,

  NOTE_B5,  EIGT,      NOTE_CS6, EIGT,      NOTE_AS5, EIGT,      NOTE_B5,  EIGT,//128
  NOTE_GS5, EIGT,      REST,     EIGT,      REST,     SIXT,
  
  NOTE_END, NOTE_END, NOTE_END, NOTE_END, NOTE_END, NOTE_END
};
