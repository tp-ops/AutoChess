/*
  AutoChess.h - Library for AutoChess system.
  Created by Tom Pennings, December 20, 2020.
*/

#include "Arduino.h"
#include "AutoChess.h"

Stepper::Stepper(int EN_PIN, int STEP_PIN, int DIR_PIN)
{
  _EN_PIN         = EN_PIN;
  _STEP_PIN       = STEP_PIN;
  _DIR_PIN        = DIR_PIN;
  _STEP_INTERVAL  = 1000;
  
  pinMode(_EN_PIN, OUTPUT);
  pinMode(_STEP_PIN, OUTPUT);
  pinMode(_DIR_PIN, OUTPUT);
}

void Stepper::enable()
{
  digitalWrite(_EN_PIN, LOW);
}

void Stepper::disable()
{
  digitalWrite(_EN_PIN, HIGH);
}

void Stepper::step_interval(int STEP_INTERVAL)
{
    _STEP_INTERVAL = STEP_INTERVAL;
}

void Stepper::drive(int STEPS, int DIR)
{
  _STEPS  = STEPS;
  _DIR    = DIR;
  
  digitalWrite(_DIR_PIN, _DIR);
  
  for (int i = 0; i <= STEPS; i++) {
    digitalWrite(_STEP_PIN, HIGH);
    delayMicroseconds(_STEP_INTERVAL);
    digitalWrite(_STEP_PIN, LOW);
  }
}