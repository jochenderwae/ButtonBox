#include <Arduino.h>
#include <avr/pgmspace.h>
#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(int buzzerPin) : MusicPlayer(buzzerPin, 144) {
}

MusicPlayer::MusicPlayer(int buzzerPin, int tempo) : _buzzerPin(buzzerPin), _tempo(tempo), _playing(false) {
  _wholenote = (60000 * 4) / _tempo;
}

void MusicPlayer::play(const int *melody) {
  if(_playing) {
    return;
  }
  
  _melody = melody;
  _nextEventTime = 0;
  _currentNote = 0;
  _playing = true;
  _nextNoteTime = 0;
}

void MusicPlayer::tick() {
   // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  if(!_playing) {
    return;
  }

  if(_nextNoteTime > millis()) {
    return;
  }

  int note = pgm_read_word_near(_melody + _currentNote);
  if(note == NOTE_END) {
    _playing = false;
    return;
  }
  
  // calculates the duration of each note
  int divider = pgm_read_word_near(_melody + _currentNote + 1);
  int noteDuration = 0;
  
  if (divider > 0) {
    // regular note, just proceed
    noteDuration = (_wholenote) / divider;
  } else if (divider < 0) {
    // dotted notes are represented with negative durations!!
    noteDuration = (_wholenote) / abs(divider);
    noteDuration *= 1.5; // increases the duration in half for dotted notes
  }

  _nextNoteTime = millis() + noteDuration;
  

  // we only play the note for 90% of the duration, leaving 10% as a pause
  tone(_buzzerPin, note, noteDuration * 0.9);

  // Wait for the specief duration before playing the next note.
  //delay(_noteDuration);

  // stop the waveform generation before the next note.
  //noTone(_buzzerPin);

  _currentNote = _currentNote + 2;
}
