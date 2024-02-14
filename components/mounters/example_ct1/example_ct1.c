#include "example_ct1.h"
#include "esp_log.h"

// Lazy way to avoid spending time on previous definition errors
// But I spend some time to make it work without adding more time building thanks to the extension
// I'll figure this one out later

static const char *TAG2 = "Mounters";

void print_message_component_one(void) 
{
    ESP_LOGI(TAG2, "Hello from Ct1! Mounters will go here..");
}