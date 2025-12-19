#include "UMSeriesD.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern "C" void app_main(void) {
    // Instantiate the wrapper (default constructor)
    UMSeriesD led;

    TickType_t lastTick = xTaskGetTickCount();
    const TickType_t delay = 50 / portTICK_PERIOD_MS; // 50ms

    // Initialize the hardware
    led.begin();

    uint8_t angle = 0;
    while (true){
        if(xTaskGetTickCount() - lastTick >= delay) {
        lastTick = xTaskGetTickCount();
            // Set the LED to the chosen color
            led.setPixelColor(UMSeriesD::colorWheel(angle));

            angle = (angle + 1) % 256;
        }
    }
}