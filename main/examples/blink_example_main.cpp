/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "esp_mac.h"
#include "UMSeriesD.h"

static const char *TAG = "example";

#define BLINK_GPIO CONFIG_BLINK_GPIO

static uint8_t s_led_state = 0;

// Instantiate the wrapper
static UMSeriesD ums3;

#ifdef CONFIG_BLINK_LED_STRIP

static void blink_led(void)
{
    if (s_led_state) {
        // Use the wrapper to set the pixel color
        ums3.setPixelColor(16, 16, 16);
    } else {
        // Turn off the pixel
        ums3.setPixelColor(0, 0, 0);
    }
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink addressable LED!");
    // Initialization is handled by ums3.begin()
}

#elif CONFIG_BLINK_BLUE_LED
static void blink_led(void)
{
    ums3.setBlueLED(s_led_state);
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink blue LED!");
    // Initialization is handled by ums3.begin()
}

#elif CONFIG_BLINK_LED_GPIO

static void blink_led(void)
{
    gpio_set_level((gpio_num_t)BLINK_GPIO, s_led_state);
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
    gpio_reset_pin((gpio_num_t)BLINK_GPIO);
    gpio_set_direction((gpio_num_t)BLINK_GPIO, GPIO_MODE_OUTPUT);
}

#else
#error "unsupported LED type"
#endif

extern "C" void app_main(void)
{
    ums3.begin();
    configure_led();

    while (1) {
        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
        blink_led();
        s_led_state = !s_led_state;
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}
