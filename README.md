# UMSeriesD ESP-IDF Wrapper for Unexpected Maker Series[D] Boards

**Supported Boards:**
- EdgeS3[D]
- TinyS3[D]
- FeatherS3[D]
- ProS3[D]


This project ports the original Unexpected Maker Series D Arduino Helper library to ESP-IDF, providing a C++ wrapper for board features. The included demonstration focuses on blinking the built-in RGB and blue LEDs on supported boards, as well as external GPIO LEDs. Addressable LEDs (e.g., WS2812) are supported via the [led_strip](https://components.espressif.com/component/espressif/led_strip) library, installed through the [component manager](main/idf_component.yml).

## Project Structure

- main/blink_example_main.cpp — Main demonstration application for blinking built-in and external LEDs.
- main/UMSeriesD.h / UMSeriesD.cpp — C++ wrapper class for UM Series[D] board features.
- main/UMSeriesD_idf.h / UMSeriesD_idf.c — ESP-IDF C helper functions for board hardware (called by the wrapper).
- main/Kconfig.projbuild — Project-specific configuration options for board features and LED selection.
- main/idf_component.yml — ESP-IDF component manager dependencies (e.g., led_strip).
- Kconfig — Root Kconfig file, includes project configuration.
- CMakeLists.txt / main/CMakeLists.txt — Build system configuration.

## How to Use Example

Before project configuration and build, ensure the target is set to ESP32-S3 using:

    idf.py set-target esp32s3

### Hardware Required

* An Unexpected Maker Series D board (EdgeS3[D], TinyS3[D], FeatherS3[D], or ProS3[D])
  * TinyS3[D], FeatherS3[D], and ProS3[D] have built-in addressable RGB LEDs (WS2812) and/or blue LEDs
  * EdgeS3[D] can be demonstrated with an external LED connected to a GPIO pin
* A USB cable for power supply and programming

See the [Unexpected Maker Series D boards](https://unexpectedmaker.com/shop.html#!/Series-D/c/183424520) for more information.

### Configure the Project

Open the project configuration menu (`idf.py menuconfig`).

In the `Example Configuration` menu:

* Select the LED type in the `Blink LED type` option.
  * Use `GPIO` for regular LED
  * Use `LED strip` for addressable LED
* If the LED type is `LED strip`, select the backend peripheral
  * `RMT` is only available for ESP targets with RMT peripheral supported
  * `SPI` is available for all ESP targets
* Set the GPIO number used for the signal in the `Blink GPIO number` option.
* Set the blinking period in the `Blink period in ms` option.

### Build and Flash

Run `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

See the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.

## Example Output

As you run the example, you will see the LED blinking, according to the previously defined period. For the addressable LED, you can also change the LED color by setting the `led_strip_set_pixel(led_strip, 0, 16, 16, 16);` (LED Strip, Pixel Number, Red, Green, Blue) with values from 0 to 255 in the [source file](main/blink_example_main.c).

```text
I (315) example: Example configured to blink addressable LED!
I (325) example: Turning the LED OFF!
I (1325) example: Turning the LED ON!
I (2325) example: Turning the LED OFF!
I (3325) example: Turning the LED ON!
I (4325) example: Turning the LED OFF!
I (5325) example: Turning the LED ON!
I (6325) example: Turning the LED OFF!
I (7325) example: Turning the LED ON!
I (8325) example: Turning the LED OFF!
```

Note: The color order could be different according to the LED model.

The pixel number indicates the pixel position in the LED strip. For a single LED, use 0.

## Troubleshooting

* If the LED isn't blinking, check the GPIO or the LED type selection in the `Example Configuration` menu.

For any technical queries, please open an [issue](https://github.com/espressif/esp-idf/issues) on GitHub. We will get back to you soon.

