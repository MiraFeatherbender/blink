#include "UMSeriesD.hpp"
#include "stdio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "battery_check";

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
        vTaskDelay(100 / portTICK_PERIOD_MS); // 100ms delay
    }
}