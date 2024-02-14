#include "esp_log.h"

// Lazy way to avoid spending time on previous definition errors
// But I spend some time to make it work without adding more time building thanks to the extension
// I'll figure this one out later

const char *TAG1 = "Booters";

void print_message_component_two(void) 
{
    ESP_LOGI(TAG1, "Hello from Ct2! Booters will go here..");
}