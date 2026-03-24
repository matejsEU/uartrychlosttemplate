#include <stdbool.h>
#include <stm8s.h>
#include "main.h"
#include "milis.h"
#include "uart1.h"
#include <stdio.h>


uint16_t ledtime = 800;
bool speed_changed = false;

void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    init_milis();
    init_uart1();

    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

}
int main(void)
{
  
    uint32_t time = 0;
    uint32_t time2 = 0;
    


    init();
    enableInterrupts();

    while (1) {
        if (ledtime > 0 && (milis() - time > ledtime)) {
            time = milis();

            REVERSE(LED); 
            //printf("%ld\n", time);
        }
        if (milis() - time2 > 500 ) {
            time2 = milis();

            if (speed_changed) {
                if (ledtime > 0) {
                    float f = 1000.0 / (2 * ledtime);
                    printf("\nT = %d ms, f = %.2f Hz\n", ledtime*2, f);
                } else {
                    printf("\nLED STOP\n");
}






















                speed_changed = false;
            }
        }
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
