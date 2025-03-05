#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_system.h>
#include <driver/gpio.h>

/*

    xTaskCreate()
    vTaskDelete()


    vTaskResume()
    vTaskResumeAll()

    vTaskSuspend()
    vTaskSuspendAll()

    vTaskDelay()

    xTaskGetTickCount()

    vTaskList()

    vTaskPrioritySet()

*/

// Task handles
TaskHandle_t xHandle_print;
TaskHandle_t xHandle_increment;

// Count variable
uint32_t count_aux = 0;


// Tasks must be implemented to never return (continuous loop)
void print_function(void *pvParameter) {

    while (1) {
        
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        printf("Counter value =  %lu\n", count_aux);
    }

}


void increment_function (void *pvParameter) {

    while (1){
        // Avoid conflicts between tasks
        vTaskSuspend(xHandle_print);
        count_aux++;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        vTaskResume(xHandle_print);
        vTaskDelay(6000 / portTICK_PERIOD_MS);
        
    }
}

void app_main(void)
{

    printf("The FreeRTOS code has been started!\n\n");

    xTaskCreate(&print_function, "PRINT", 2048, NULL, 5, &xHandle_print);
    xTaskCreate(&increment_function, "INCR", 2048, NULL, 5, &xHandle_increment);

}