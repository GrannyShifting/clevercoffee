/**
 * @file SWSwitch.h
 *
 * @brief A software state controlled switch
 */

#include "SWSwitch.h"
#include "GPIOPin.h"

SWSwitch::SWSwitch(uint8_t initialState) :
    Switch(Switch::SW_TRIG, Switch::SW_MODE), currentState(initialState) {
}

bool SWSwitch::isPressed() {
    return currentState == HIGH;
}

bool SWSwitch::longPressDetected() {
    return false;
}

void SWSwitch::setState(uint8_t state) {
    currentState = state;
}
