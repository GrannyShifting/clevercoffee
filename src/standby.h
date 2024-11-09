/**
 * @file standby.h
 *
 * @brief Standby mode
 */

#pragma once

#define TIME_TO_DISPLAY_OFF 60000000    // 1 min
#define TIME_TO_STANDBY     1800000000  // 30 mins
uint8_t displayAwake = 1;
hw_timer_t* timerDisplay = NULL;
hw_timer_t* timerStandby = NULL;

void sleepDisplay()
{
    displayAwake = 0;
}

void sleepPID()
{
    pidON = 0;
}

void initStandbyDisplayTimers()
{
    //ESP32 runs at 80MHz. Divider is 80, so each tick is 1us
    timerDisplay = timerBegin(1, 80, true); 
    timerStandby = timerBegin(2, 80, true);
    timerAttachInterrupt(timerDisplay, &sleepDisplay, true);
    timerAttachInterrupt(timerStandby, &sleepPID, true);
    timerAlarmWrite(timerDisplay, TIME_TO_DISPLAY_OFF, true); //set time in us, 60s
    timerAlarmWrite(timerStandby, TIME_TO_STANDBY, true); //set time in us, 30mins
}

void enableStandyDisplayTimer()
{
    timerAlarmEnable(timerDisplay);
    timerAlarmEnable(timerStandby);
}

void restartDisplayTime()
{
    LOG(INFO, "restarting display timer");
    timerRestart(timerDisplay);
    displayAwake = 1;
}

void restartStandbyTime()
{
    LOG(INFO, "restarting standby timer");
    timerRestart(timerStandby);
}


// unsigned long standbyModeStartTimeMillis = millis();
// unsigned long standbyDisplayStartTimeMillis = millis();
// // unsigned long standbyModeRemainingTimeMillis = standbyModeTime * 60 * 1000;
// unsigned long standbyModeRemainingTimeMillis = 0;
// unsigned long standbyModeRemainingTimeDisplayOffMillis = TIME_TO_DISPLAY_OFF * 60 * 1000;
// unsigned long lastStandbyTimeMillis = standbyModeStartTimeMillis;
// unsigned long lastStandbyDisplayTimeMillis = standbyModeStartTimeMillis;
// unsigned long timeSinceStandbyMillis = 0;

// /**
//  * @brief Decrements the remaining standby time every second, counting down from the configured duration
//  */
// void updateStandbyTimer(void) {
//     unsigned long currentTime = millis();
//     if (millis()%1000 == 0)
//         LOG(INFO, "in updateStandbyTimer");
//     if ((standbyModeRemainingTimeMillis != 0) && ((currentTime % 1000) == 0) && (currentTime != lastStandbyTimeMillis)) {
//         unsigned long standbyModeTimeMillis = standbyModeTime * 60 * 1000;
//         long elapsedTime = currentTime - standbyModeStartTimeMillis;
//         lastStandbyTimeMillis = currentTime;
        
//         if (standbyModeTimeMillis > elapsedTime) {
//             standbyModeRemainingTimeMillis = standbyModeTimeMillis - elapsedTime;

//             if ((currentTime % 60000) == 0) {
//                 LOGF(INFO, "Standby time remaining: %i minutes", standbyModeRemainingTimeMillis / 60000);
//             }
//         }
//         else {
//             standbyModeRemainingTimeMillis = 0;
//             LOG(INFO, "Entering standby mode...");
//         }
//     }
//     if ((standbyModeRemainingTimeDisplayOffMillis != 0) && ((currentTime % 1000) == 0) && (currentTime != lastStandbyDisplayTimeMillis)) {
//         unsigned long standbyModeTimeMillis = TIME_TO_DISPLAY_OFF * 60 * 1000;
//         long elapsedTime = currentTime - standbyDisplayStartTimeMillis;
//         lastStandbyDisplayTimeMillis = currentTime;
//         if (millis()%1000 == 0)
//             LOG(INFO, "in standbyModeRemainingTimeDisplayOffMillis");
//         if (standbyModeTimeMillis > elapsedTime) {
//             standbyModeRemainingTimeDisplayOffMillis = standbyModeTimeMillis - elapsedTime;

//             if ((currentTime % 60000) == 0) {
//                 LOGF(INFO, "Standby time until display is turned off: %i minutes", standbyModeRemainingTimeDisplayOffMillis / 60000);
//             }
//         }
//         else {
//             standbyModeRemainingTimeDisplayOffMillis = 0;
//             LOG(INFO, "Turning off display...");
//         }
//     }
// }

// void resetMachineStandbyTimer(void) {
//     standbyModeRemainingTimeMillis = standbyModeTime * 60 * 1000;
//     standbyModeStartTimeMillis = millis();

//     LOGF(INFO, "Resetting standby timer to %i minutes", (int)standbyModeTime);
// }

// void clrMachineStandbyTimer(void) {
//     standbyModeRemainingTimeMillis = 0;

//     LOGF(INFO, "Clearing standby timer");
// }

// void resetOLEDStandbyTimer(void) {
//     standbyModeRemainingTimeDisplayOffMillis = TIME_TO_DISPLAY_OFF * 60 * 1000;
//     standbyDisplayStartTimeMillis = millis();

//     LOGF(INFO, "Resetting display timer to %i minute(s)", (int)TIME_TO_DISPLAY_OFF);
// }
