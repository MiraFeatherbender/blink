# Copilot Instructions for UM-Dseries-menuconfig Blink Project

## Project Overview
- ESP-IDF C project for ESP32-family chips, demonstrating LED blinking using either GPIO or addressable LED strips (e.g., WS2812).
- Main logic in `main/blink_example_main.c`.
- Project configuration via Kconfig (`Kconfig`, `main/Kconfig.projbuild`).
- Supports multiple ESP32 targets (see `README.md` for list).

## Key Files & Structure
- `main/blink_example_main.c`: Main application logic, handles both GPIO and addressable LED blinking.
- `main/Kconfig.projbuild`: Project-specific Kconfig options (LED type, backend, GPIO, etc.).
- `Kconfig`: Root Kconfig, sources project Kconfig.
- `CMakeLists.txt` and `main/CMakeLists.txt`: Standard ESP-IDF build setup.
- `pytest_blink.py`: Pytest-based test for binary size and basic validation.
- `sdkconfig*`: Project configuration files, generated/used by ESP-IDF.

## Build & Flash Workflow
- Set target chip: `idf.py set-target <chip_name>`
- Configure: `idf.py menuconfig` (choose LED type, backend, GPIO, etc.)
- Build, flash, and monitor: `idf.py -p PORT flash monitor`
- Exit monitor: `Ctrl-]`

## Testing
- Run `pytest pytest_blink.py` to execute the provided test (requires `pytest-embedded-idf`).
- Test checks binary size and basic build validity.

## Project Conventions & Patterns
- Uses ESP-IDF component manager for dependencies (see `main/idf_component.yml`).
- LED type and backend are configurable at build time via Kconfig.
- Code uses `CONFIG_*` macros from `sdkconfig.h` for conditional logic.
- Logging via ESP-IDF's `ESP_LOG*` macros.
- Follows ESP-IDF minimal build pattern (`idf_build_set_property(MINIMAL_BUILD ON)`).

## Integration Points
- External: [led_strip](https://components.espressif.com/component/espressif/led_strip) library for addressable LEDs.
- Kconfig and CMake integration for flexible configuration and build.

## Examples
- To blink a regular LED: select `GPIO` in menuconfig, set `Blink GPIO number`.
- To use an addressable LED strip: select `LED strip` and backend (`RMT` or `SPI`).

## References
- See `README.md` for hardware requirements and more usage details.
- For new components, follow the pattern in `main/` and update Kconfig/CMake as needed.

---

*Edit this file to update project-specific AI agent instructions. See https://aka.ms/vscode-instructions-docs for more info.*
