/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


const int BTN_BRANCO = 16;
const int LED_BRANCO = 20;
const int BOBINA_1 = 27;
const int BOBINA_2 = 26;
const int BOBINA_3 = 22;
const int BOBINA_4 = 18;


int main() {
    stdio_init_all();

    gpio_init(LED_BRANCO);
    gpio_set_dir(LED_BRANCO, GPIO_OUT);

    gpio_init(BTN_BRANCO);
    gpio_set_dir(BTN_BRANCO, GPIO_IN);
    gpio_pull_up(BTN_BRANCO);

    gpio_init(BOBINA_1);
    gpio_set_dir(BOBINA_1,GPIO_OUT);

    gpio_init(BOBINA_2);
    gpio_set_dir(BOBINA_2,GPIO_OUT);

    gpio_init(BOBINA_3);
    gpio_set_dir(BOBINA_3,GPIO_OUT);

    gpio_init(BOBINA_4);
    gpio_set_dir(BOBINA_4,GPIO_OUT);

    while (true) {
        

        
        if (!gpio_get(BTN_BRANCO)){
            gpio_put(LED_BRANCO,1);
            
            int i = 0;
            
            while (i< 2048/4){
                gpio_put(BOBINA_1, 1);
                sleep_ms(5);

                gpio_put(BOBINA_1, 0);
                gpio_put(BOBINA_2, 1);
                sleep_ms(5);

                gpio_put(BOBINA_2, 0);
                gpio_put(BOBINA_3, 1);
                sleep_ms(5);

                gpio_put(BOBINA_3, 0);
                gpio_put(BOBINA_4, 1);
                sleep_ms(5);

                gpio_put(BOBINA_4,0);
                
                i++;

            }

            gpio_put(LED_BRANCO,0);
            
            while(!gpio_get(BTN_BRANCO)){};
        }
        
        
    }
}

