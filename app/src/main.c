// Assignement 1: Hello World

// #include<zephyr/kernel.h>

// int main(void)
// {
//     printk("Hello World! %s\n", CONFIG_BOARD);
//     return 0;
// }


// Assignement 2: Blinky


#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led =
    GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main(void)
{
    if (!gpio_is_ready_dt(&led)) {
        return 0;
    }

    gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);

    while (1) {
        gpio_pin_toggle_dt(&led);
        k_sleep(K_MSEC(CONFIG_BLINK_SLEEP_TIME_MS));
    }

    return 0;
}