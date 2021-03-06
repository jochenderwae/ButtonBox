//#include <Arduino.h>
#include <avr/pgmspace.h>
#include "MusicPlayer.h"

// taken from https://github.com/robsoncouto/arduino-songs/

extern const PROGMEM int odeToJoy[] = {
  
  114, // tempo
  
  NOTE_E4,QART,      NOTE_E4,QART,  NOTE_F4,QART,  NOTE_G4,QART,//1
  NOTE_G4,QART,      NOTE_F4,QART,  NOTE_E4,QART,  NOTE_D4,QART,
  NOTE_C4,QART,      NOTE_C4,QART,  NOTE_D4,QART,  NOTE_E4,QART,
  NOTE_E4,QART_DOT,  NOTE_D4,EIGT,  NOTE_D4,HALF,

  NOTE_E4,QART,      NOTE_E4,QART,  NOTE_F4,QART,  NOTE_G4,QART,//4
  NOTE_G4,QART,      NOTE_F4,QART,  NOTE_E4,QART,  NOTE_D4,QART,
  NOTE_C4,QART,      NOTE_C4,QART,  NOTE_D4,QART,  NOTE_E4,QART,
  NOTE_D4,QART_DOT,  NOTE_C4,EIGT,  NOTE_C4,HALF,

  NOTE_D4,QART,      NOTE_D4,QART,  NOTE_E4,QART,  NOTE_C4,QART,//8
  NOTE_D4,QART,      NOTE_E4,EIGT,  NOTE_F4,EIGT,  NOTE_E4,QART, NOTE_C4,QART,
  NOTE_D4,QART,      NOTE_E4,EIGT,  NOTE_F4,EIGT,  NOTE_E4,QART, NOTE_D4,QART,
  NOTE_C4,QART,      NOTE_D4,QART,  NOTE_G3,HALF,

  NOTE_E4,QART,      NOTE_E4,QART,  NOTE_F4,QART,  NOTE_G4,QART,//12
  NOTE_G4,QART,      NOTE_F4,QART,  NOTE_E4,QART,  NOTE_D4,QART,
  NOTE_C4,QART,      NOTE_C4,QART,  NOTE_D4,QART,  NOTE_E4,QART,
  NOTE_D4,QART_DOT,  NOTE_C4,EIGT,  NOTE_C4,HALF,
  NOTE_END, NOTE_END, NOTE_END, NOTE_END, NOTE_END, NOTE_END
};
