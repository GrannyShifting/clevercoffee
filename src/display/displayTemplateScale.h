/**
 * @file displayTemplateScale.h
 *
 * @brief Display template with brew scale
 *
 */

#pragma once
#include "displayCommon.h"

/**
 * @brief Send data to display
 */
void printScreen() {

    if (inMenu && !((inMenu == 2) && (currMenuItem == MENU_BREW))) {
        displayMenu();
        return;
    }

    // Show shot timer:
    if (displayShottimer()) {
        // Display was updated, end here
        return;
    }

    // Print the machine state
    if (displayMachineState()) {
        // Display was updated, end here
        return;
    }

    if (scaleFailure) {
        u8g2.print("fault");
    }
    else {
        if (machineState == kBrew) {
            u8g2.print(weightBrew, 0);
        }
        else {
            u8g2.print(weight, 0);
        }

        if (weightSetpoint > 0) {
            u8g2.print("/");
            u8g2.print(weightSetpoint, 0);
        }

        u8g2.print(" (");
        u8g2.print(weightBrew, 1);
        u8g2.print(")");
    }

#if (FEATURE_PRESSURESENSOR == 1)
    u8g2.setCursor(32, 46);
    u8g2.print("P: ");
    u8g2.print(inputPressure, 1);
#endif

}
