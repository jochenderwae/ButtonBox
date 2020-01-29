#include <Arduino.h>
#include <avr/pgmspace.h>
#include "MusicPlayer.h"


MusicPlayer::MusicPlayer(int buzzerPin) : _buzzerPin(buzzerPin), _playing(false), 
                                          _melody(NULL), _currentNote(0),
                                          _nextNoteTime(0), _notePlayed(false) {
}



void MusicPlayer::play(const int *melody) {
  // ignore if something is playing
  if(_playing) {
    return;
  }
  
  _melody = melody;
  _currentNote = 0;
  _playing = true;
  _nextNoteTime = 0;

  // the first value is the tempo
  int tempo = pgm_read_word_near(_melody + _currentNote);
  _currentNote++;
  _wholenote = (60 * 1000 * 4) / tempo;
}



void MusicPlayer::tick() {
  // if nothing is playing, skip
  if(!_playing) {
    return;
  }

  // if it's not yet time to play the next note, skip
  if(_nextNoteTime > millis()) {
    _notePlayed = false;
    return;
  }

  // read the next note and duration
  int note    = pgm_read_word_near(_melody + _currentNote);
  int divider = pgm_read_word_near(_melody + _currentNote + 1);

  // if we reached the end of the song, stop playing and skip
  if(note == NOTE_END) {
    _playing = false;
    return;
  }
  
  // calculates the duration of each note
  int noteDuration = 0;
  if (divider > 0) {
    // regular note, just proceed
    noteDuration = (_wholenote) / divider;
  } else if (divider < 0) {
    // dotted notes are represented with negative durations!!
    noteDuration = (_wholenote) / abs(divider);
    noteDuration *= 1.5; // increases the duration in half for dotted notes
  }

  // calculate the time to start the next note
  _nextNoteTime = millis() + noteDuration;
  

  // don't play anything if it's a rest note
  if(note != REST) {
    // we only play the note for 90% of the duration, leaving 10% as a pause
    _notePlayed = true;
    tone(_buzzerPin, note, noteDuration * 0.9);
  }

  // move pointer to the next note
  _currentNote = _currentNote + 2;
}


bool MusicPlayer::isNotePlayed() {
  return _notePlayed;
}
