/**
 * @file Relay.cpp
 *
 * @brief A relay connected to a GPIO pin
 */

#include "Relay.h"
#include "GPIOPin.h"
#include "pinmapping.h"
#include "Logger.h"

Relay::Relay(GPIOPin& gpioInstance, const TriggerType trigger) :
    gpio(gpioInstance), relayTrigger(trigger) {
}

void Relay::on() const {

    // LOGF(INFO, "%d", (int)gpio.pin);

    if (gpio.pin == PIN_PUMP)
        gpio.setType(GPIOPin::OUT);

    if (relayTrigger == HIGH_TRIGGER) {
        gpio.write(HIGH);
    }
    else {
        gpio.write(LOW);
    }
}

void Relay::off() const {
    if (gpio.pin == PIN_PUMP){
        gpio.setType(GPIOPin::IN_ANALOG);
        return;
    }

    if (relayTrigger == HIGH_TRIGGER) {
        gpio.write(LOW);
    }
    else {
        gpio.write(HIGH);
    }
}

GPIOPin& Relay::getGPIOInstance() const {
    return gpio;
}
