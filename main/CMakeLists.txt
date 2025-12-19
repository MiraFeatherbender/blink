if(CONFIG_EXAMPLE_COLORWHEEL)
    set(EXAMPLE_SRC "examples/colorwheel.cpp")
elseif(CONFIG_EXAMPLE_BLINK)
    set(EXAMPLE_SRC "examples/blink_example_main.cpp")
endif()

idf_component_register(
    SRCS
        "${EXAMPLE_SRC}"
        "src/UMSeriesD_idf.c"
        "src/UMSeriesD.cpp"
    INCLUDE_DIRS "src"
    REQUIRES driver esp_adc led_strip
)