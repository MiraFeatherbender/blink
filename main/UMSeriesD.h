#pragma once
#include <stdint.h>

class UMSeriesD {
public:
    void begin();
    void setLDO2Power(bool on);
    void setPixelPower(bool on);
    void setPixelColor(uint8_t r, uint8_t g, uint8_t b);
    void setPixelColor(uint32_t rgb);
    void setPixelBrightness(uint8_t brightness);
    static uint32_t color(uint8_t r, uint8_t g, uint8_t b);
    static uint32_t colorWheel(uint8_t pos);
    void setBlueLED(bool on);
    float getLightSensorVoltage();
    void toggleBlueLED();
    float getBatteryVoltage();
    bool getVbusPresent();
    void setAntennaExternal(bool state);
};