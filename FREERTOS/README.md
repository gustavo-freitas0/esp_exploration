Overview
===

FreeRTOS is a king of SMP (Symmetric Multiprocessing). A SMP is a computing architecture where two or more identical CPU cores are connected to a single shared main memory and controlled by a single operation system.

Freertos provide by Espressif is based on Vanilla FREERTOS v10.5.1 and contains significant modiications. This RTOS is supported on numerous single-core MCUs and SoCs.


## IDF FreeRTOS tasks:

 * Can only be in one of the following states: Running, Ready, Blocked or Suspended.
 * Tipically implemented as an infinite loop
 * Should never return




Important points:
---

* IDF FreeRTOS can also be configured for single-core by enabling the CONFIG_FREERTOS_UNICORE option.

References:
---

* [FreeRTOS IDF](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/freertos_idf.html)