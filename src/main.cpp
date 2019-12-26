#include <Arduino.h>

#define INDICATOR_CC PORTD
#define INDICATOR_CA PORTB

// digits for indicator with common catode
#define CLEAR_CC INDICATOR_CC=0x00
#define SET_ZERO_CC INDICATOR_CC=0x3F
#define SET_ONE_CC INDICATOR_CC=0x06
#define SET_TWO_CC INDICATOR_CC=0x5B
#define SET_THREE_CC INDICATOR_CC=0x4F
#define SET_FOUR_CC INDICATOR_CC=0x66
#define SET_FIVE_CC INDICATOR_CC=0x6D
#define SET_SIX_CC INDICATOR_CC=0x7D
#define SET_SEVEN_CC INDICATOR_CC=0x07
#define SET_EIGHT_CC INDICATOR_CC=0x7F
#define SET_NINE_CC INDICATOR_CC=0x6F

// digits for indicator with common anode
#define CLEAR_CA INDICATOR_CA=0xFF
#define SET_ZERO_CA INDICATOR_CA=0xC0
#define SET_ONE_CA INDICATOR_CA=0xF9
#define SET_TWO_CA INDICATOR_CA=0xA4
#define SET_THREE_CA INDICATOR_CA=0xB0
#define SET_FOUR_CA INDICATOR_CA=0x99
#define SET_FIVE_CA INDICATOR_CA=0x92
#define SET_SIX_CA INDICATOR_CA=0x82
#define SET_SEVEN_CA INDICATOR_CA=0xF8
#define SET_EIGHT_CA INDICATOR_CA=0x80
#define SET_NINE_CA INDICATOR_CA=0x90

void setNumber(uint8_t number) {
  switch (number) {
    case 0:
      SET_ZERO_CC;
      SET_ZERO_CA;
      break;
    case 1:
      SET_ONE_CC;
      SET_ONE_CA;
      break;
    case 2:
      SET_TWO_CC;
      SET_TWO_CA;
      break;
    case 3:
      SET_THREE_CC;
      SET_THREE_CA;
      break;
    case 4:
      SET_FOUR_CC;
      SET_FOUR_CA;
      break;
    case 5:
      SET_FIVE_CC;
      SET_FIVE_CA;
      break;
    case 6:
      SET_SIX_CC;
      SET_SIX_CA;
      break;
    case 7:
      SET_SEVEN_CC;
      SET_SEVEN_CA;
      break;
    case 8:
      SET_EIGHT_CC;
      SET_EIGHT_CA;
      break;
    case 9:
      SET_NINE_CC;
      SET_NINE_CA;
      break;
  }
}

void setup() {
  DDRD = 0xFF;
  DDRB = 0xFF;
  CLEAR_CC;
  CLEAR_CA;
}

void loop() {
  for (int8_t i = 9; i >= 0; i--) {
    setNumber(i);

    _delay_ms(1000);
  }
}