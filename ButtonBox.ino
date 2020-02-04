#include <WiFiManager.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>

#include <IoAbstraction.h>
#include <IoAbstractionWire.h>
#include <Wire.h>
#include "RotaryEncoder.h"
#include "MusicPlayer.h"

MultiIoAbstractionRef multiIo = multiIoExpander(10);
// https://github.com/davetcc/IoAbstraction

/*
 * IO definitions
 */
#define ENCODER_A 10
#define ENCODER_B 11
#define ENCODER_BUTTON 12
#define BAR_LED_0 13
#define BAR_LED_1 14
#define BAR_LED_2 15
#define BAR_LED_3 16
#define BAR_BUTTON 17

#define CIRCLE_0 27
#define CIRCLE_1 26
#define CIRCLE_2 25
#define CIRCLE_3 24
#define CIRCLE_4 23
#define CIRCLE_5 22
#define CIRCLE_6 21
#define CIRCLE_7 20

#define ROUND_BUTTON 37
#define ROUND_LED 36
#define I_II_BUTTON_II 35
#define I_II_BUTTON_I 34
#define I_II_LED_I 33
#define I_II_LED_II 32

#define TRIANGLE_BUTTON 47
#define TRIANGLE_LED_0 46
#define TRIANGLE_LED_1 45
#define TRIANGLE_LED_2 44
#define TOGGLE_BUTTON_R 43
#define TOGGLE_BUTTON_L 42
#define TOGGLE_LED_L 41
#define TOGGLE_LED_R 40

#define SQUARE_BUTTON 57
#define SQUARE_LED_0 56
#define SQUARE_LED_1 55
#define SQUARE_LED_2 54
#define SQUARE_LED_3 53
#define I_BUTTON 52
#define I_LED 51

#define GREEN_BUTTON 67
#define GREEN_LED 66
#define SLIDE_BUTTON_0 65
#define SLIDE_BUTTON_1 64
#define SLIDE_BUTTON_2 63
#define SLIDE_LED_0 62
#define SLIDE_LED_1 61
#define SLIDE_LED_2 60

byte allLeds[] = {
  BAR_LED_0, BAR_LED_1, BAR_LED_2, BAR_LED_3,
  CIRCLE_0, CIRCLE_1, CIRCLE_2, CIRCLE_3,
  CIRCLE_4, CIRCLE_5, CIRCLE_6, CIRCLE_7,
  ROUND_LED, I_II_LED_I, I_II_LED_II, TRIANGLE_LED_0,
  TRIANGLE_LED_1, TRIANGLE_LED_2, TOGGLE_LED_L, TOGGLE_LED_R,
  SQUARE_LED_0, SQUARE_LED_1, SQUARE_LED_2, SQUARE_LED_3,
  I_LED, GREEN_LED, SLIDE_LED_0, SLIDE_LED_1, SLIDE_LED_2};
int ledCount = sizeof(allLeds) / sizeof(allLeds[0]);


/*
 * Music
 */
extern const PROGMEM int asabranca[];
extern const PROGMEM int bloodytears[];
extern const PROGMEM int cannonInD[];
extern const PROGMEM int cantina[];
extern const PROGMEM int greenHillZone[];
extern const PROGMEM int greenSleeves[];
extern const PROGMEM int hedwigsTheme[];
extern const PROGMEM int imperialMarch[];
extern const PROGMEM int keyboardCat[];
extern const PROGMEM int miiChannelTheme[];
extern const PROGMEM int minueteInG[];
extern const PROGMEM int nokiaRingtone[];
extern const PROGMEM int odeToJoy[];
extern const PROGMEM int overworldTheme[];
extern const PROGMEM int pacman[];
extern const PROGMEM int pinkPanther[];
extern const PROGMEM int princeIgor[];
extern const PROGMEM int professorLaytonsTheme[];
extern const PROGMEM int puloDaGaita[];
extern const PROGMEM int songOfStorms[];
extern const PROGMEM int starWars[];
extern const PROGMEM int takeOnMe[];
extern const PROGMEM int tetris[];
extern const PROGMEM int theLick[];
extern const PROGMEM int theLionSleepsTonight[];
extern const PROGMEM int zeldaLullaby[];

MusicPlayer musicPlayer = MusicPlayer(D4);

/**
 * WiFi stuff
 */
WiFiServer server(80);
WiFiManager wifiManager;

/**
 * set up rotary encoder
 */
LoopingRotaryEncoder encoder = LoopingRotaryEncoder(multiIo, ENCODER_A, ENCODER_B);

void setup()
{
  Serial.begin(115200);

  wifiManager.autoConnect("ButtonBox");

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  //server.begin();

  ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  Serial.println("Ready");

  
  
  Wire.begin();
  multiIoAddExpander(multiIo, ioFrom8574(0x20, D5), 10);
  multiIoAddExpander(multiIo, ioFrom8574(0x21), 10);
  multiIoAddExpander(multiIo, ioFrom8574(0x22), 10);
  multiIoAddExpander(multiIo, ioFrom8574(0x23), 10);
  multiIoAddExpander(multiIo, ioFrom8574(0x24), 10);
  multiIoAddExpander(multiIo, ioFrom8574(0x25), 10);

  ioDevicePinMode(multiIo, ENCODER_A, INPUT);
  ioDevicePinMode(multiIo, ENCODER_B, INPUT);
  ioDevicePinMode(multiIo, ENCODER_BUTTON, INPUT);
  ioDevicePinMode(multiIo, BAR_LED_0, OUTPUT);
  ioDevicePinMode(multiIo, BAR_LED_1, OUTPUT);
  ioDevicePinMode(multiIo, BAR_LED_2, OUTPUT);
  ioDevicePinMode(multiIo, BAR_LED_3, OUTPUT);
  ioDevicePinMode(multiIo, BAR_BUTTON, INPUT);

  ioDevicePinMode(multiIo, CIRCLE_0, OUTPUT);
  ioDevicePinMode(multiIo, CIRCLE_1, OUTPUT);
  ioDevicePinMode(multiIo, CIRCLE_2, OUTPUT);
  ioDevicePinMode(multiIo, CIRCLE_3, OUTPUT);
  ioDevicePinMode(multiIo, CIRCLE_4, OUTPUT);
  ioDevicePinMode(multiIo, CIRCLE_5, OUTPUT);
  ioDevicePinMode(multiIo, CIRCLE_6, OUTPUT);
  ioDevicePinMode(multiIo, CIRCLE_7, OUTPUT);

  ioDevicePinMode(multiIo, ROUND_BUTTON, INPUT);
  ioDevicePinMode(multiIo, ROUND_LED, OUTPUT);
  ioDevicePinMode(multiIo, I_II_BUTTON_I, INPUT);
  ioDevicePinMode(multiIo, I_II_BUTTON_II, INPUT);
  ioDevicePinMode(multiIo, I_II_LED_I, OUTPUT);
  ioDevicePinMode(multiIo, I_II_LED_II, OUTPUT);

  ioDevicePinMode(multiIo, TRIANGLE_BUTTON, INPUT);
  ioDevicePinMode(multiIo, TRIANGLE_LED_0, OUTPUT);
  ioDevicePinMode(multiIo, TRIANGLE_LED_1, OUTPUT);
  ioDevicePinMode(multiIo, TRIANGLE_LED_2, OUTPUT);
  ioDevicePinMode(multiIo, TOGGLE_BUTTON_L, INPUT);
  ioDevicePinMode(multiIo, TOGGLE_BUTTON_R, INPUT);
  ioDevicePinMode(multiIo, TOGGLE_LED_L, OUTPUT);
  ioDevicePinMode(multiIo, TOGGLE_LED_R, OUTPUT);

  ioDevicePinMode(multiIo, SQUARE_LED_0, OUTPUT);
  ioDevicePinMode(multiIo, SQUARE_LED_1, OUTPUT);
  ioDevicePinMode(multiIo, SQUARE_LED_2, OUTPUT);
  ioDevicePinMode(multiIo, SQUARE_LED_3, OUTPUT);
  ioDevicePinMode(multiIo, SQUARE_BUTTON, INPUT);
  ioDevicePinMode(multiIo, I_LED, OUTPUT);
  ioDevicePinMode(multiIo, I_BUTTON, INPUT);

  ioDevicePinMode(multiIo, GREEN_BUTTON, INPUT);
  ioDevicePinMode(multiIo, GREEN_LED, INPUT);
  ioDevicePinMode(multiIo, SLIDE_BUTTON_0, INPUT);
  ioDevicePinMode(multiIo, SLIDE_BUTTON_1, INPUT);
  ioDevicePinMode(multiIo, SLIDE_BUTTON_2, INPUT);
  ioDevicePinMode(multiIo, SLIDE_LED_0, INPUT);
  ioDevicePinMode(multiIo, SLIDE_LED_1, INPUT);
  ioDevicePinMode(multiIo, SLIDE_LED_2, INPUT);


  musicPlayer.play(nokiaRingtone);
}

long pos = 0;
int bar = 0;

bool barB = false;
bool prevBarB = false;
bool barBTime = 0;
bool roundB = false;
bool i_b = false;
bool ii_b = false;
bool triangle = false;
bool toggleL = false;
bool toggleR = false;
bool square = false;
bool io = false;
bool green = false;
bool slider0 = false;
bool slider1 = false;
bool slider2 = false;

int i_ii = 0;
int toggle = 0;
int slider = 0;

void loop()
{
  ArduinoOTA.handle();
  
  musicPlayer.tick();
  if(musicPlayer.isPlaying()) {
    if(musicPlayer.isNotePlayed()) {
      randomSeed(musicPlayer.getLastNote());
      int ledOnCount = 5;
      for(int ledIndex = 0; ledIndex < ledCount; ledIndex++) {
        bool ledOn = false;
        if(ledOnCount > 0) {
          if(ledOnCount >= random(0, ledCount - ledIndex)) {
            ledOn = true;
            ledOnCount--;
          }
        }
        ioDevicePinMode(multiIo, allLeds[ledIndex], ledOn ? HIGH : LOW);
      }
    }
  } else {
    for(int i = 20; i < 28; i++) {
      ioDevicePinMode(multiIo, i, (pos % 8 == i % 8) ? HIGH : LOW);
    }
    ioDevicePinMode(multiIo, BAR_LED_0,      bar == 0       ? HIGH : LOW);
    ioDevicePinMode(multiIo, BAR_LED_1,      bar == 1       ? HIGH : LOW);
    ioDevicePinMode(multiIo, BAR_LED_2,      bar == 2       ? HIGH : LOW);
    ioDevicePinMode(multiIo, BAR_LED_3,      bar == 3       ? HIGH : LOW);
    ioDevicePinMode(multiIo, I_II_LED_I,     (i_ii == -1)   ? HIGH : LOW);
    ioDevicePinMode(multiIo, I_II_LED_II,    (i_ii == 1)    ? HIGH : LOW);
    ioDevicePinMode(multiIo, ROUND_LED,      roundB         ? HIGH : LOW);
    ioDevicePinMode(multiIo, TRIANGLE_LED_0, triangle       ? HIGH : LOW);
    ioDevicePinMode(multiIo, TRIANGLE_LED_1, triangle       ? HIGH : LOW);
    ioDevicePinMode(multiIo, TRIANGLE_LED_2, triangle       ? HIGH : LOW);
    ioDevicePinMode(multiIo, TOGGLE_LED_L,   (toggle == -1) ? HIGH : LOW);
    ioDevicePinMode(multiIo, TOGGLE_LED_R,   (toggle == 1)  ? HIGH : LOW);
    ioDevicePinMode(multiIo, SQUARE_LED_0,   square         ? HIGH : LOW);
    ioDevicePinMode(multiIo, SQUARE_LED_1,   square         ? HIGH : LOW);
    ioDevicePinMode(multiIo, SQUARE_LED_2,   square         ? HIGH : LOW);
    ioDevicePinMode(multiIo, SQUARE_LED_3,   square         ? HIGH : LOW);
    ioDevicePinMode(multiIo, I_LED,          io             ? HIGH : LOW);
    ioDevicePinMode(multiIo, SLIDE_LED_0,    (slider == 0)  ? HIGH : LOW);
    ioDevicePinMode(multiIo, SLIDE_LED_1,    (slider == 1)  ? HIGH : LOW);
    ioDevicePinMode(multiIo, SLIDE_LED_2,    (slider == 2)  ? HIGH : LOW);
    ioDevicePinMode(multiIo, GREEN_LED,      green          ? HIGH : LOW);
  }
  
  ioDeviceSync(multiIo);

  encoder.tick();
  pos = encoder.getPosition();
  if(pos < 0) {
    encoder.setPosition(7);
    pos = 7;
  } else if(pos > 7) {
    encoder.setPosition(0);
    pos = 0;
  }
  
  //encoder = ioDeviceDigitalRead(multiIo, ENCODER_BUTTON) == 0;
  barB     = ioDeviceDigitalRead(multiIo, BAR_BUTTON) == 0;
  roundB   = ioDeviceDigitalRead(multiIo, ROUND_BUTTON) == 0;
  i_b      = ioDeviceDigitalRead(multiIo, I_II_BUTTON_I) == 0;
  ii_b     = ioDeviceDigitalRead(multiIo, I_II_BUTTON_II) == 0;
  triangle = ioDeviceDigitalRead(multiIo, TRIANGLE_BUTTON) == 0;
  toggleL  = ioDeviceDigitalRead(multiIo, TOGGLE_BUTTON_L) == 0;
  toggleR  = ioDeviceDigitalRead(multiIo, TOGGLE_BUTTON_R) == 0;
  square   = ioDeviceDigitalRead(multiIo, SQUARE_BUTTON) == 0;
  io       = ioDeviceDigitalRead(multiIo, I_BUTTON) == 0;
  green    = ioDeviceDigitalRead(multiIo, GREEN_BUTTON) == 0;
  slider0  = ioDeviceDigitalRead(multiIo, SLIDE_BUTTON_0) == 0;
  slider1  = ioDeviceDigitalRead(multiIo, SLIDE_BUTTON_1) == 0;
  slider2  = ioDeviceDigitalRead(multiIo, SLIDE_BUTTON_2) == 0;
  
  if(i_b) {
    i_ii = -1;
  } else if(ii_b) {
    i_ii = 1;
  } else {
    i_ii = 0;
  }
  
  if(toggleL) {
    toggle = -1;
  } else if(toggleR) {
    toggle = 1;
  } else {
    toggle = 0;
  }
  
  if(slider0) {
    slider = 0;
  } else if(slider1) {
    slider = 1;
  } else if(slider2) {
    slider = 2;
  }

  if(barB && ! prevBarB) {
    barBTime = millis();
  }
  prevBarB = barB;
  if(barB) {
    bar = ((millis() - barBTime) / 1000) % 4;
  }

  if(io) {
    switch(bar) {
      case 0:
        musicPlayer.play(cannonInD/*odeToJoy*/);
      case 1:
        musicPlayer.play(theLick);
      case 2:
        musicPlayer.play(keyboardCat/*pacman*/);
      case 3:
        musicPlayer.play(minueteInG/*bloodytears*/);
    }
  }
  
  //delay(50);
}
