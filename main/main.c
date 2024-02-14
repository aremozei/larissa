#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "portmacro.h"
#include "sdkconfig.h"
#include "example_ct1.h"
#include "example_ct2.c"

static const char *TAG = "example";

#define BLINK_GPIO CONFIG_BLINK_GPIO
static uint8_t s_led_state = 0;

static void blink_led(void) 
{
    gpio_set_level(BLINK_GPIO, s_led_state);
}

static void configure_led(void)
{
    ESP_LOGI(TAG, "Welcome to Larissa!..");
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

void app_main(void)
{
    configure_led();

    while(1)
    {
        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
        print_message_component_one();
        print_message_component_two();
        blink_led();
        s_led_state = !s_led_state;
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }

}
