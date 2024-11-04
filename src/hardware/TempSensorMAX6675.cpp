/**
 * @file TempSensorMAX6675.cpp
 *
 * @brief Handler for MAX6675 temperature sensor
 */

#include "TempSensorMAX6675.h"
#include "Logger.h"

TempSensorMAX6675::TempSensorMAX6675(int THERM_PIN_SCK, int THERM_PIN_CS, int THERM_PIN_SO) {
    // Set pin to receive signal from the TSic 306
    max6675Sensor_ = new MAX6675(THERM_PIN_SCK, THERM_PIN_CS, THERM_PIN_SO);
}

bool TempSensorMAX6675::sample_temperature(double& temperature) const {
    auto temp = (double)(max6675Sensor_->readCelsius());

    if (temp < 0) {
        LOG(WARNING, "Temperature below 0");
        return false;
    }
    else if (temp >150) {
        LOG(WARNING, "Temperature too high");
        return false;
    }

    temperature = temp;
    return true;
}
