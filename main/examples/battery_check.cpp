#include "UMSeriesD.hpp"
#include "stdio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BATTERY_CHECK_INTERVAL_MS 3000
static const char *TAG = "battery_check";

void checkBattery(UMSeriesD& batteryChecker); // Prototype

extern "C" void app_main(void){

    // Instantiate the wrapper
    UMSeriesD batteryChecker;

    // Initialize the hardware
    batteryChecker.begin();
    ESP_LOGI(TAG,"begin");

    batteryChecker.setPixelBrightness(255/3);
    ESP_LOGI(TAG, "setPixelBrightness");

    batteryChecker.fgSetup();
    ESP_LOGI(TAG, "MAX17048 version: %d\n", batteryChecker.fgVersion());

    while(1){
        checkBattery(batteryChecker);
        vTaskDelay(BATTERY_CHECK_INTERVAL_MS / portTICK_PERIOD_MS);
    }
}

void checkBattery(UMSeriesD& batteryChecker){
    float voltage = batteryChecker.getBatteryVoltage();

    if(batteryChecker.getVbusPresent())
    {
        if(voltage < 4.0){
            batteryChecker.setPixelColor(0x0000FF); // Blue for charging
        } else {
            batteryChecker.setPixelColor(0x000000); // Off for full
        }
        ESP_LOGI(TAG, "Running from VBUS - Battery: %.2f V", voltage);
    } 
    else 
    {
        if(voltage >= 3.6){
            batteryChecker.setPixelColor(0x00FF00); // Green for high
        } else if(voltage >= 3.3){
            batteryChecker.setPixelColor(0xFF8800); // Orange for medium
        } else {
            batteryChecker.setPixelColor(0xFF0000); // Red for low
        }
        ESP_LOGI(TAG, "Running from Battery: %.2f V", voltage);
    }
}