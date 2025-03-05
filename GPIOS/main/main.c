#include <stdio.h>
#include <driver/gpio.h>

// Define the GPIOs
#define GPIO_OUT_PIN_SEL (GPIO_NUM_)

// 
gpio_config_t out_conf = {};


void app_main(void)
{

    out_conf.mode = GPIO_MODE_OUTPUT;
    
    out_conf.pin_bit_mask = 



    gpio_get_level();

    gpio_set_level();

    // gpio confiuration
    gpio_config();


}
