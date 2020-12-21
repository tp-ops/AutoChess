/*
  AutoChess.h - Library for AutoChess system.
  Created by Tom Pennings, December 20, 2020.
*/
#ifndef AutoChess_h
#define AutoChess_h

#include "Arduino.h"

class Stepper
{
  public:
    Stepper(int EN_PIN, int STEP_PIN, int DIR_PIN);
    void enable();
    void disable();
    void step_interval(int STEP_INTERVAL);
    void drive(int STEPS, int DIR);
  private:
    int _EN_PIN;
    int _STEP_PIN;
    int _DIR_PIN;
    int _STEP_INTERVAL;
    int _STEPS;
    int _DIR;
};

#endif