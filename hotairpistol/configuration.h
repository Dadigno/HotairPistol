

#ifdef INPUTBT
#define PIN_BT0 4
#define PIN_BT1 2
#define REED 9
#define PIN_POT A0
#include "input.h"
#endif

#ifdef LCDI2C
#include <LiquidCrystal_I2C.h> // Libreria LCD I2C
#include "lcd.h"
#define SDA A4
#define SCL A5
#endif

#ifdef THERMO
#define thermoDO 12
#define thermoCS 11
#define thermoCLK 10
#include "max6675.h"
#include "thermo.h"
#endif

#define PIN_FAN1 5
#define PIN_FAN2 6
#define PIN_HEAT 8


#define DEFAULT_T 300
