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
    if (machineState == kPidDisabled || machineState == kStandby)
        displayAwake = 0;
}

void sleepPID()
{
    pidON = 0;
    steamON = 0;
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