/**
 * @file SWSwitch.h
 *
 * @brief A software state controlled switch
 */

#pragma once

#include <cstdint>

#include "GPIOPin.h"
#include "Switch.h"

class SWSwitch : public Switch {
    public:
        /**
         * @brief I/O Switch connected to a GPIO pin
         * @details This class represents a switch which is connected to a GPIO pin of the controller. It holds its own
         *          instance of the GPIO pin.
         *
         * @param pinNumber GPIO pin number
         * @param pinType GPIO pin type
         * @param switchType Type of the switch
         * @param mode Operation mode of the switch
         */
        SWSwitch(uint8_t initialState = LOW);

        /**
         * @brief Switch reading (pressed, not pressed)
         * @details This function reads the connected GPIO pin and returns a debounced reading of the witch
         * @return True of activated, false otherwise
         */
        bool isPressed() override ;

        /**
         * @brief Check if a long press of the momentary switch has been detected
         * @details Always returns false for toggle switches
         * @return True if the momentary switch is held down, false otherwise
         */
        bool longPressDetected() override ;

        /**
         * @brief Sets the state of the switch
         * @details 
         * @return Nothing
         */
        void setState(uint8_t state) override ;

    private:

        uint8_t currentState;
};
