#ifndef __GPIO_H__
#define __GPIO_H__

#include "main.h"

typedef enum
{
	DOT_NUM = 1,
	DASH_NUM = 2
}NUMS;

typedef enum
{
	GREEN = GPIO_PIN_13,
	YELLOW = GPIO_PIN_14,
	RED = GPIO_PIN_15
}GPIO_COLOR;

typedef enum
{
  YELLOW_DELAY = 400,
  RED_DELAY = 400,
  GREEN_SMALL_DELAY = 500,
  GREEN_LARGE_DELAY = 1000,
  DASH_DELAY = GREEN_LARGE_DELAY,
  DOT_DELAY = GREEN_SMALL_DELAY
}GPIO_DELAY;

typedef enum
{
	PRESSED = 1,
	NOT_PRESSED
} BTN_STATE;

void MX_GPIO_Init(void);

void writeYellow();
void writeRed();
void writeGreenWithDelay();

uint32_t readBtnState();
#endif
