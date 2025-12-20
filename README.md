# UMSeriesD ESP-IDF Wrapper for Unexpected Maker Series[D] Boards

**Supported Boards:**
- EdgeS3[D]
- TinyS3[D]
- FeatherS3[D]
- ProS3[D]


This project ports the original [Unexpected Maker Series D Arduino Helper library](https://github.com/UnexpectedMaker/seriesd_arduino_helper) to ESP-IDF, providing a C++ wrapper for board features. The included demonstration focuses on blinking the built-in RGB and blue LEDs on supported boards, as well as external GPIO LEDs. Addressable LEDs (e.g., WS2812) are supported via the [led_strip](https://components.espressif.com/component/espressif/led_strip) library, installed through the [component manager](main/idf_component.yml).

## Project Structure

```
.
├── main/
│   ├── examples/
│   │   ├── blink_example_main.cpp   # Example: Blinking built-in, blue, and external LEDs
│   │   └── colorwheel.cpp           # Example: Cycling RGB LED through color wheel
│   ├── src/
│   │   ├── UMSeriesD.hpp            # C++ wrapper class header
│   │   ├── UMSeriesD.cpp            # C++ wrapper class implementation
│   │   ├── UMSeriesD_idf.h          # ESP-IDF C helper header
│   │   └── UMSeriesD_idf.c          # ESP-IDF C helper implementation
│   ├── Kconfig.projbuild            # Project-specific configuration options
│   └── idf_component.yml            # ESP-IDF component manager dependencies (e.g., led_strip)
├── Kconfig                          # Root Kconfig file, includes project configuration
├── CMakeLists.txt                   # Root build system configuration
└── main/CMakeLists.txt              # Main build system configuration
```

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

In the "UM Series[D] Board Configuration" menu:

* **Select your board type** in the "Select UM Series[D] board" option.
* **Select the example to build** in the "Example Selection" menu:
  * **Color Wheel Example** — Cycles the built-in RGB LED through the color wheel (TinyS3[D], FeatherS3[D], ProS3[D])
  * **Blink Example** — Blinks the RGB, blue, or external LED (all boards)
* If you select the **Blink Example**, additional options will appear:
  * **Blink LED type** — Choose the LED type:
    * **GPIO** for an external LED (EdgeS3[D] or any board with a manual LED on a GPIO pin)
    * **RBG LED** for the built-in addressable RGB LED (TinyS3[D], FeatherS3[D], ProS3[D])
    * **Blue LED** for the built-in blue LED (FeatherS3[D] only)
  * If using **GPIO** mode, set the GPIO number in the "External GPIO number to blink" option.
  * If using **Blue LED** mode, it defaults to the built-in pin on FeatherS3[D].
  * Set the blinking period in the "Blink period in ms" option.

### Build and Flash

Run `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

See the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.

## Example Output

As you run the example, you will see the LED blinking, according to the previously defined period. For the RGB LED, you can also change the LED color by calling `ums3.setPixelColor(r, g, b)` in the [source file](main/blink_example_main.cpp), with values from 0 to 255.

```text
I (315) example: Example configured to blink addressable LED!
I (325) example: Turning the LED OFF!
I (1325) example: Turning the LED ON!
I (2325) example: Turning the LED OFF!
I (3325) example: Turning the LED ON!
```

Note: The color order could be different according to the LED model.

## Troubleshooting

* If the LED isn't blinking, check the GPIO or the LED type selection in the `UM Series[D] Board Configuration` menu.
* If using a D series board other than ProS3D, double check the pin numbers in [Kconfig.projbuild](main/Kconfig.projbuild) against your pinout card.
* Ensure you have selected the correct board type in menuconfig.
* Make sure your board is properly powered and the USB cable is securely connected.
* Check the serial monitor for any error messages or warnings.
* If changes to configuration or code don’t seem to take effect, try running `idf.py fullclean` and rebuilding the project.

