#include <stdio.h>

#include "clk.h"
#include "board.h"
#include "periph_conf.h"
#include "timex.h"
#include "ztimer.h"
#define BTN_STATE 1
static int LED_PATTERN[] = {1, 2};
static volatile int button_state = 0;

static void delay(void)
{
    if (IS_USED(MODULE_ZTIMER)) {
        ztimer_sleep(ZTIMER_USEC, 100 * US_PER_SEC);
    }
    else {
       
        uint32_t loops = coreclk() / 20;
        for (volatile uint32_t i = 0; i < loops; i++) { }
    }
}



static void toggle_led_pattern(void)
{
    for (size_t i = 0; i < sizeof(LED_PATTERN) / sizeof(LED_PATTERN[0]); i++) {
        // Turn on LEDs based on the pattern
        
        if (LED_PATTERN[i] & 1) {
           LED0_ON;
        }

       
        if (LED_PATTERN[i] & 2) {
            LED1_ON;
        }

        delay();

        // Turn off all LEDs
        LED0_OFF;
        

        LED1_OFF;
       

        delay();
    }
}


static void button_pressed_action(void)
{
 
    printf("Button Pressed!\n");

 
    int temp=  LED_PATTERN[0];
    LED_PATTERN[0] =  LED_PATTERN[1];
    LED_PATTERN[1] =  temp;
   

   
}

int main(void)
{
    while (1) {
        delay();

        
              button_pressed_action();
       
        toggle_led_pattern();
    }

    return 0;
}
