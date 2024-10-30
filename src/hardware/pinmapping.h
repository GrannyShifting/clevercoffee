/**
 * @file pinmapping.h
 *
 * @brief Default GPIO pin mapping
 *
 */

#pragma once

/**
 * Input Pins
 */

// Switches/Buttons
#define PIN_POWERSWITCH -1
#define PIN_BREWSWITCH  -1
#define PIN_STEAMSWITCH -1
#define PIN_WATERSWITCH -1

// Rotary encoder switch
#define PIN_ROTARY_DT  26 
#define PIN_ROTARY_CLK 27 
#define PIN_ROTARY_SW  25 
#define PIN_ENCODER_VCC -1 
#define ROTARY_ENCODER_STEPS 4 

// Sensors
#define PIN_TEMPSENSOR  16
#define PIN_WATERSENSOR -1
#define PIN_HXDAT       33 // Brew scale data pin 1
#define PIN_HXDAT2      -1 // Brew scale data pin 2
#define PIN_HXCLK       32 // Brew scale clock pin

// Adafruit library for K-type thermocouple
// Bit-bangs the SPI-compatible interface
// 3.3V-5V
#define PIN_THERM_SCK   4 // K-Type Thermocouple
#define PIN_THERM_CS    2 // K-Type Thermocouple
#define PIN_THERM_SO    15 // K-Type Thermocouple

/**
 * Output pins
 */

// Relays
#define PIN_VALVE  17
#define PIN_PUMP   18
#define PIN_HEATER 5

// LEDs
#define PIN_STATUSLED 31
#define PIN_BREWLED   19
#define PIN_STEAMLED  1

// Periphery
#define PIN_ZC -1 // Dimmer circuit Zero Crossing

/**
 * Bidirectional Pins
 */
#define PIN_I2CSCL 22
#define PIN_I2CSDA 21
