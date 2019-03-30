#include <OLED_I2C.h>
#include <stdlib.h>
#include <time.h>

OLED  myOLED(SDA, SCL, 8);

void ball_move();
extern uint8_t SmallFont[];
const short LB = 4;
const short RB = 7;
static const unsigned char PROGMEM loose[] = {
  0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0,
  0xF8, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0xFF, 0x0F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xC0, 0xF0, 0xF0, 0xF0, 0xF8, 0xFC, 0xFC, 0xE0, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFE, 0xFC,
  0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x7C, 0x7C, 0x3C, 0x38, 0x70, 0x00, 0xFE, 0xFF, 0xFF, 0xFE, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x0F, 0x7F, 0xFF, 0xFE, 0x80, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0x00,
  0x00, 0x00, 0x00, 0xE0, 0xFC, 0xFE, 0xFF, 0x7F, 0x0F, 0x0F, 0x87, 0xC0, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x30, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0x80, 0xF8, 0xFC, 0xFE, 0xFF, 0x7F, 0x0F, 0x0F, 0xC3, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0xF8, 0xFC, 0xFE, 0xFF, 0x7F, 0x0F, 0x0F, 0xC3, 0xC0, 0x80, 0x00, 0x00, 0x00, 0xF8,
  0xFF, 0x1F, 0x03, 0x01, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x01,
  0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFC, 0xF8, 0xFF, 0x3F, 0x07, 0x00, 0x00,
  0x00, 0xE1, 0xFC, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x07, 0x7F, 0xFF, 0xFF, 0xE0, 0x00,
  0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x7F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,
  0xE1, 0xFF, 0xFF, 0xFF, 0x7F, 0x01, 0x00, 0x00, 0x00, 0x0F, 0x7F, 0xFF, 0xFC, 0xC0, 0x00, 0x00,
  0xE1, 0xFF, 0xFF, 0xFF, 0x7F, 0x07, 0x00, 0x00, 0x00, 0x0F, 0x7F, 0xFF, 0xFC, 0xC0, 0x00, 0x01,
  0x0F, 0x3E, 0x78, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC1, 0xF0, 0xF0,
  0xF0, 0xF0, 0x70, 0x60, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x77, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0x00,
  0x00, 0x00, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x1F, 0x00, 0x00, 0x00,
  0x77, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
  0x77, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x7C, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xC1, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x07, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x07, 0x7F, 0xFF, 0xFF, 0xFC, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
  0x00, 0x00, 0x7F, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF0, 0x3F, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFC, 0xC0, 0xC0, 0xC0, 0xE0, 0xFF, 0xFF, 0x7F, 0x07, 0x00, 0x00,
  0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFC, 0xC0, 0xC0, 0xC0, 0xE0, 0xFF, 0xFF, 0x7F, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x7C, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xE0, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5F, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0x07, 0x0E, 0x0C, 0x0C, 0x0E, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x60, 0x40, 0x40, 0x40, 0x40, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x17, 0x1F,
  0x3E, 0x3C, 0x78, 0x78, 0x70, 0x70, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xE0, 0xE0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x07, 0x01
};
static const unsigned char PROGMEM win[] = {
  0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xF0, 0x06, 0xE1, 0xF1, 0x07, 0x1F, 0xFC, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
  0xEC, 0x18, 0x18, 0x10, 0x00, 0x00, 0x00, 0xE0, 0x38, 0x8C, 0x64, 0x10, 0x10, 0x30, 0x60, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xF8, 0xF8, 0x18, 0x0C, 0x00, 0x00, 0xE0, 0x3C, 0x8E,
  0x1C, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x08, 0xFC, 0xFE,
  0xC2, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x04, 0x02,
  0x06, 0xFC, 0x00, 0x00, 0x06, 0x06, 0xFE, 0x02, 0x03, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0xFE,
  0xFE, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x06, 0x79, 0x81, 0x47, 0x3E, 0x00, 0x00,
  0xFE, 0xFE, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0x00,
  0x00, 0x0F, 0x70, 0xE3, 0x70, 0x00, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C,
  0x03, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x1F, 0x00, 0x40, 0x01, 0x64, 0x0C, 0x00, 0x00, 0x00, 0x01,
  0x1F, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x60, 0x49,
  0x1E, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F,
  0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x03, 0x0E, 0x04,
  0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x1F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xE0, 0x00, 0x00, 0xC0, 0x1F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x00, 0x00, 0x00, 0x07, 0x1E, 0x07, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x0F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x3E, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0x00, 0x07, 0x7F, 0xC0, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xE0, 0xF0, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3F, 0xF8, 0x00, 0x00, 0xF8, 0x03, 0x00, 0x03, 0xFF, 0x80, 0x00, 0x00, 0x00, 0xFC, 0x0F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0x00, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x80, 0x3E, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xC0, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFF, 0x00, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x00, 0xFE, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xF0, 0x0C, 0x8C, 0x7C, 0x00, 0x80,
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x03, 0x7E, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x84, 0x00, 0x00, 0x00, 0x00, 0x8F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x87, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFE, 0x03, 0x31, 0x11, 0x02, 0xC0, 0x38, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1C, 0x70, 0xC0, 0x80, 0x00, 0x00, 0x80, 0x60, 0x38,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0F, 0x38, 0xC0, 0x80, 0x00, 0x80, 0x80, 0x60,
  0x1C, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFE, 0xF8, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xFF, 0x80, 0x80, 0x80, 0x3F, 0xC0, 0x81, 0x80, 0xE0, 0x3F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x19,
  0x89, 0xFF, 0x00, 0x00, 0x03, 0x99, 0xC3, 0x38, 0x00, 0x0E, 0x11, 0x89, 0xFF, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x07, 0x0E, 0x0E, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM logo[] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF8, 0xF8, 0xF8, 0xE8, 0x00,
  0x00, 0x00, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0x38, 0xF8, 0xF8, 0xF0, 0x00, 0xE0, 0xF0, 0xF8, 0x38,
  0x38, 0x38, 0x78, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0xE8, 0xF8, 0xF8, 0xF8, 0x80, 0x00, 0x00, 0x08,
  0xF8, 0xF8, 0xF8, 0xE0, 0x80, 0x00, 0xF8, 0xF8, 0xF8, 0x00, 0xE0, 0xF0, 0xF8, 0x38, 0x38, 0x38,
  0xF8, 0xF0, 0xE0, 0x00, 0xF8, 0xF8, 0xF8, 0x00, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0x38, 0xF8, 0xF0,
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFC, 0xFF, 0x3F, 0x39, 0x3F, 0x7F, 0xFE,
  0xF0, 0x80, 0xFF, 0xFF, 0xFF, 0x0E, 0x1E, 0x7E, 0xFF, 0xF7, 0x83, 0x0F, 0x7F, 0xFF, 0xF0, 0xC0,
  0xC0, 0xC0, 0xE0, 0xF0, 0x70, 0x80, 0xF0, 0xFF, 0x3F, 0x3F, 0x3B, 0x3F, 0xFF, 0xF8, 0xC0, 0x00,
  0xFF, 0xFF, 0x03, 0x0F, 0x1F, 0x7E, 0xFF, 0xFF, 0xFF, 0x06, 0x7F, 0xFF, 0xF0, 0xC0, 0xC0, 0xC0,
  0xF0, 0xFF, 0x7F, 0x06, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xF1, 0xFF,
  0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x06, 0xFE, 0xFE, 0x8E, 0x8E, 0x8E, 0xDE, 0xFC, 0xFC, 0xE0, 0xF8, 0xFC, 0x3E, 0x1E, 0x0E, 0x1E,
  0x7C, 0xFC, 0xF0, 0x00, 0xFE, 0xFE, 0xFE, 0x8E, 0x8E, 0x9E, 0xFE, 0xFC, 0xF8, 0x1E, 0x0E, 0x0E,
  0xFE, 0xFE, 0x0E, 0x0E, 0x1E, 0x06, 0xFE, 0xFE, 0x8E, 0x8E, 0x8E, 0xCE, 0x0E, 0x1E, 0x06, 0xFE,
  0xFE, 0x0E, 0x0E, 0x0E, 0x1E, 0xFC, 0xFC, 0xF0, 0x00, 0x00, 0x00, 0x06, 0xFE, 0xFE, 0x8E, 0x8E,
  0x8E, 0xCE, 0x0E, 0x1E, 0xF0, 0xF8, 0xFC, 0x1E, 0x0E, 0x1E, 0x3E, 0xFC, 0xF8, 0xE0, 0x06, 0xFE,
  0xFE, 0x8E, 0x8E, 0x8E, 0x9E, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFC, 0x7C, 0x1E, 0x0E,
  0x1E, 0x3E, 0xFC, 0xF8, 0xC0, 0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE,
  0x8E, 0x8E, 0x8E, 0xCE, 0x0E, 0x1E, 0x00, 0xFE, 0xFE, 0xFE, 0x0E, 0x0E, 0x1E, 0xFC, 0xFC, 0xF0,
  0x40, 0x7F, 0x7F, 0x43, 0x03, 0x03, 0x03, 0x03, 0x01, 0x07, 0x3F, 0x7F, 0x78, 0xF0, 0xE0, 0xF0,
  0x7E, 0x3F, 0x1F, 0x00, 0x7F, 0x7F, 0x7F, 0x03, 0x0F, 0x7F, 0x7F, 0x79, 0x40, 0x00, 0x00, 0x40,
  0x7F, 0x7F, 0x40, 0x00, 0x00, 0x40, 0x7F, 0x7F, 0x73, 0x73, 0x73, 0x73, 0x70, 0xF0, 0x40, 0x7F,
  0x7F, 0x70, 0x70, 0x70, 0x70, 0x7F, 0x3F, 0x1F, 0x00, 0x00, 0x00, 0x40, 0x7F, 0x7F, 0x43, 0x03,
  0x03, 0x03, 0x00, 0x00, 0x1F, 0x3F, 0x7F, 0x70, 0xF0, 0xF0, 0x78, 0x7F, 0x3F, 0x07, 0x40, 0x7F,
  0x7F, 0x43, 0x03, 0x1F, 0x7F, 0x7F, 0x71, 0x40, 0x00, 0x00, 0x00, 0x1F, 0x7F, 0x7C, 0xF0, 0xE0,
  0xF0, 0x78, 0x7F, 0x3F, 0x07, 0x7F, 0x7F, 0x7F, 0x70, 0x70, 0x70, 0x70, 0xF0, 0xF0, 0x7F, 0x7F,
  0x73, 0x73, 0x73, 0x73, 0x70, 0xF0, 0x00, 0x7F, 0x7F, 0x7F, 0x70, 0x70, 0x70, 0x7E, 0x3F, 0x1F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF,
  0xFF, 0x07, 0x07, 0x07, 0x0F, 0xFF, 0xFE, 0xF0, 0xFF, 0xFF, 0xFF, 0x00, 0x7E, 0xFF, 0xFF, 0xE7,
  0xE7, 0xE7, 0xFF, 0xCE, 0x00, 0xFF, 0xFF, 0xFF, 0xE7, 0xE7, 0xE7, 0xFF, 0xFE, 0x00, 0xFF, 0xFF,
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0xFF, 0x3F, 0xFF, 0xF8, 0xC0, 0x00, 0x03,
  0x0F, 0x3F, 0xFF, 0xF8, 0xFC, 0x7F, 0x1F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x3F,
  0x3F, 0x38, 0x38, 0x38, 0x3C, 0x1F, 0x0F, 0x01, 0x3F, 0x3F, 0x3F, 0x00, 0x1E, 0x1E, 0x3C, 0x39,
  0x39, 0x3D, 0x1F, 0x0F, 0x00, 0x3F, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F,
  0x3F, 0x38, 0x38, 0x38, 0x38, 0x3C, 0x3C, 0x3F, 0x3F, 0x07, 0x07, 0x07, 0x3F, 0x3F, 0x3E, 0x30,
  0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM rect[] =
{ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
static const unsigned char PROGMEM brect[] =
{ 0xFF, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0xFF};
static const unsigned char PROGMEM hbrect[] =
{ 0xFF, 0xBB, 0xDD, 0xBB, 0xDD, 0xBB, 0xDD, 0xBB, 0xDD, 0xFF};
struct Rect {
  short x, y;
  byte h, w;
  Rect(short x, short y, byte w, byte h) {
    this->x = x;
    this->y = y;
    this->h = h;
    this->w = w;
  }
  Rect() {
    this->x = 0;
    this->y = 0;
    this->h = 0;
    this->w = 0;
  }
  ~Rect() {}
};
struct object {
  byte  hp, dead;
  Rect bnd;
  object() {
   // type = -1;
    hp = -1;
    dead = -1;
  }
  object(short x, short y, short type) {
    Rect sample(x, y, 10, 4);
    this->dead = 0;
    switch (type) {
      case 0:
        this->hp = 1;
        break;
      case 1:
        this->hp = 2;
        break;
      case 2:
        this->hp = 3;
        break;
    }
    this->bnd.x = sample.x;
    this->bnd.y = sample.y;
    this->bnd.h = sample.h;
    this->bnd.w = sample.w;
  }
  ~object() {}
};
Rect player(52, 60, 20, 3), ball(61, 56, 3, 3);
short directionx = 0;
short directiony = -1;
short enterc = 1;
short php = 5;
short n = 24;
short dc = 0;
short x = 10;
short y = 10;
bool game = 1;
bool wine=0;
byte level=1;
char lv[]={'1',0};
char lf[]={'5',0};
object *blocks;


void setup()
{
  pinMode(LB, INPUT);
  pinMode(RB, OUTPUT);
  srand(time(NULL));
  blocks = (struct object *)malloc(n * sizeof(struct object));
  for (int c = 0; c < n; c++) {
    object a(x, y, rand() % 3);
    blocks[c] = a;
    if ((c + 1) % 8 == 0) {
      y += 10;
      x = 10;
    }
    else {
      x += 15;
    }
  }
  myOLED.begin();
  myOLED.setFont(SmallFont);
  randomSeed(analogRead(0));
  myOLED.drawBitmap(0, 0, logo, 128, 64);
  myOLED.update();
  delay(4000);
  myOLED.clrScr();
  myOLED.print("Level: ", 40, 12);
  myOLED.print(lv, 78, 12);
  myOLED.print("Lifes: ", 40, 32);
  myOLED.print(lf, 78, 32);
  myOLED.update();
  delay(2000);
  myOLED.clrScr();
}

void loop()
{
  while (game) {
    if (php == 0 || dc == n) {
      break;
    }
    dc = 0;
    for (int c = 0; c < n; c++) {
      if (blocks[c].dead == 0) {
        switch (blocks[c].hp) {
          case 1:
            myOLED.drawBitmap(blocks[c].bnd.x, blocks[c].bnd.y, brect, blocks[c].bnd.w, blocks[c].bnd.h); 
            break;
          case 2:
            myOLED.drawBitmap(blocks[c].bnd.x, blocks[c].bnd.y, hbrect, blocks[c].bnd.w, blocks[c].bnd.h); 
            break;
          case 3:
            myOLED.drawBitmap(blocks[c].bnd.x, blocks[c].bnd.y, rect, blocks[c].bnd.w, blocks[c].bnd.h);
            break;
        }
      }
      else {
        dc++;
      }
    }
    myOLED.drawBitmap(player.x, player.y, rect, player.w, player.h);
    myOLED.drawBitmap(ball.x, ball.y, rect, ball.w, ball.h);
    if (digitalRead(LB) == HIGH) {
      if (player.x > 0) {
        player.x -= 2;
        if (enterc == 0) {
          ball.x -= 2;
        }
      }
    }
    else if (digitalRead(RB) == HIGH) {
      if (player.x < 128 - player.w) {
        player.x += 2;
        if (enterc == 0) {
          ball.x += 2;
        }
      }
    }
    ball_move();
    myOLED.update();
    //delay(100);
    myOLED.clrScr();
  }
  myOLED.clrScr();
  if (php == 0) {
    myOLED.drawBitmap(0, 0, loose, 128, 64);
    game = 0;
  }
  else if (php > 0 && wine!=1) {
    player.x=52;
    player.y=60;
    ball.x=61;
    ball.y=56;
    directionx=0;
    directiony=-1;
    level++;
    php++;
    lv[0]++;
    lf[0]='0'+php;
    myOLED.print("Level: ", 40, 12);
    myOLED.print(lv, 78, 12);
    myOLED.print("Lifes: ", 40, 32);
    myOLED.print(lf, 78, 32);
  }
  if(wine!=1){
  myOLED.update();
  delay(2000);
  }
  if(blocks!=NULL){
    free(blocks);
  }
  byte  sc=1;
  byte b=1;
  switch(level){
  case 2:
  n=36;
  blocks = (struct object *)malloc(n * sizeof(struct object));
  sc=1;
  b=1;
  x=58;
  y=10;
  for (int c = 0; c < n; c++) {
    object a(x, y, rand() % 3);
    blocks[c] = a;
    if ((c+1) % b == 0) {
      sc+=2;
      b+=sc;
      y += 4;
      x = blocks[0].bnd.x-a.bnd.w*(sc/2);
    }
    else {
      x += 10;
  }
  }
  break;
  case 3:
  byte d;
  n=39;
  blocks = (struct object *)malloc(n * sizeof(struct object));
  sc=1;
  d=2;
  b=1; 
  x=38;
  y=10;
  for (int c = 0; c < 13; c++) {
    object a(x, y, rand() % 3);
    blocks[c] = a;
    if ((c+1) % b == 0) {
      sc+=d;
      b+=sc;
      y += 4;
      x = blocks[0].bnd.x-a.bnd.w*(sc/2);
      if(b==9){
        d=-d;
      }
    }
    else {
      x += 10;
    }
  }
  sc=1;
  b=1;
  d=2;
  x=78;
  y=10;
    for (int c = 0; c < 13; c++) {
    object a(x, y, rand() % 3);
    blocks[c+13] = a;
    if ((c+1) % b == 0) {
      sc+=d;
      b+=sc;
      y += 4;
      x = blocks[0+13].bnd.x-a.bnd.w*(sc/2);
      if(b==9){
        d=-d;
      }
    }
    else {
      x += 10;
    }
  }
  sc=1;
  b=1;
  d=2;
  x=58;
  y=22;
  for (int c = 0; c < 13; c++) {
    object a(x, y, rand() % 3);
    blocks[c+26] = a;
    if ((c+1) % b == 0) {
      sc+=d;
      b+=sc;
      y += 4;
      x = blocks[0+26].bnd.x-a.bnd.w*(sc/2);
      if(b==9){
        d=-d;
      }
    }
    else {
      x += 10;
    }
  }
  break;
  case 4:
  wine=1;
  myOLED.drawBitmap(0, 0, win, 128, 64);
  myOLED.update();
  break;
  }
}

void ball_move() {//physics
  short br, bt, bl, bd,upc,dwc,lfc,rgc;
  short rn = rand() % 2;
  bd = ball.y + ball.w;
  bt = ball.y;
  bl = ball.x;
  br = ball.x + ball.h;
  upc=0;
  dwc=0;
  lfc=0;
  rgc=0;
  for (int c = 0; c < n; c++) {
    if (blocks[c].dead == 0) {
      short right, left, top, down, hit;
      right = blocks[c].bnd.x + blocks[c].bnd.w;
      left = blocks[c].bnd.x;
      top = blocks[c].bnd.y;
      down = blocks[c].bnd.y + blocks[c].bnd.h;
      hit = 0;
      if ((((bl >= left) && (bl <= right)) || ((br >= left) && (br <= right))) && (bd == top)) {
        if ((bl == right) && (bd == top) && ((directionx == directiony))) {
          continue;
        }
        else if ((br == left) && (bd == top) && (directionx == -directiony)) {
          continue;
        }
        //else if((br == left) && (bd == top) && (directionx == -1) && (directiony == -1)){
        //  continue;
        //}
        else {
          hit = 1;
          dwc++;
          directiony = -directiony;
        }
      }
      else if ((((bl >= left) && (bl <= right)) || ((br >= left) && (br <= right))) && (bt == down)) {
        if (bl == right && bt == down && directionx == -directiony) {
          continue;
        }
        else if (br == left && bt == down && directionx == directiony) {
          continue;
        }
        else {
          hit = 1;
          upc++;
          directiony = -directiony;
        }
        if (directionx == 0) {
          directionx = 1;
          if (rn == 0) {
            directionx = -1;
          }
        }

      }
      else if ((((bt > top) && (bt <= down)) || ((bd > top) && (bd <= down))) && (bl == right)) {
        hit = 1;
        lfc++;
        if (directionx > 0) {
          directionx = -1;
        }
        else {
          directionx = 1;
        }
      }
      else if ((((bt > top) && (bt <= down)) || ((bd > top) && (bd <= down))) && (br == left)) {
        hit = 1;
        rgc++;
        if (directionx > 0) {
          directionx = -1;
        }
        else if (directionx == 0) {
          directionx = -1;
        }
        else {
          directionx = 1;
        }
      }
      if (hit == 1) {
        blocks[c].hp--;
        if (blocks[c].hp == 0) {
          blocks[c].dead = 1;
        }
      }
    }
  }
  if(upc>1||dwc>1){
        directiony=-directiony;
  }
  else if(lfc>1||rgc>1){
        directionx=-directionx;
  }
  if ((player.y == bd) && (((bl >= player.x) && (bl <= player.x + player.w)) || ((br >= player.x) && (br <= player.x + player.w)))) {
    if (directiony > 0) {
      directiony = -1;
    }
    else {
      directiony = 1;
    }
    if (bl <= 0 || br >= 128) {
      directionx = -directionx;
    }
  }
  else if (ball.y <= 0) {
    if (directiony > 0) {
      directiony = -1;
    }
    else {
      directiony = 1;
    }
    if (directionx == 0) {
      directionx = 1;
      if (rn == 0) {
        directionx = -1;
      }
    }
    if (bl <= 0 || br >= 128) {
      directionx = -directionx;
    }
  }
  else if (ball.x < 0) {
    if (directionx > 0) {
      directionx = -1;
    }
    else {
      directionx = 1;
    }
  }
  else if (br > 128) {
    if (directionx > 0) {
      directionx = -1;
    }
    else {
      directionx = 1;
    }
  }
  else if (ball.y == 80) {
    php -= 1;
    ball.x = player.x + 10;
    ball.y = player.y - ball.h;
    directionx = 0;
    directiony = -1;
  }
  ball.x += directionx;
  ball.y += directiony;
}
