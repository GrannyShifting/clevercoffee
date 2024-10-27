/**
 * @file TempSensorMAX6675.h
 *
 * @brief Handler for MAX6675 temperature sensor
 */

#pragma once

#include "TempSensor.h"
#include <max6675.h>

class TempSensorMAX6675 : public TempSensor {
    public:
        TempSensorMAX6675(int THERM_PIN_SCK,int THERM_PIN_CS,int THERM_PIN_SO);

    protected:
        bool sample_temperature(double& temperature) const override;

    private:
        MAX6675* max6675Sensor_;
};
