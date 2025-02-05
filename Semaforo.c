#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_LED 13     // Pino do LED vermelho
#define YELLOW_LED 12  // Pino do LED amarelo
#define GREEN_LED 11  // Pino do LED verde

int state = 0 ;

bool repeating_timer_callback(struct repeating_timer *timer) {
  switch (state) {
        case 0:
            gpio_put(RED_LED, 1);    // Apaga o LED vermelho
            gpio_put(YELLOW_LED, 0); // Acende o LED amarelo
            gpio_put(GREEN_LED, 1);  // Mantém o LED verde apagado
            state = 1;               // Avança para o próximo estado
            break;
        case 1:
            gpio_put(RED_LED, 0);    // Mantém o LED vermelho apagado
            gpio_put(YELLOW_LED, 0); // Apaga o LED amarelo
            gpio_put(GREEN_LED, 1);  // Acende o LED verde
            state = 2;               // Avança para o próximo estado
            break;
        case 2:
            gpio_put(RED_LED, 1);    // Acende o LED vermelho
            gpio_put(YELLOW_LED, 0); // Mantém o LED amarelo apagado
            gpio_put(GREEN_LED, 0);  // Apaga o LED verde
            state = 0;               // Volta ao estado inicial
            break;
    }
    return true; // Continua repetindo o timer
}

int main() {
    stdio_init_all();
    int counter = 0;
    // Configura os pinos dos LEDs como saída
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_init(YELLOW_LED);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);

     // Inicializa o estado dos LEDs
    gpio_put(RED_LED, 1);    // LED vermelho aceso
    gpio_put(YELLOW_LED, 0); // LED amarelo apagado
    gpio_put(GREEN_LED, 0);  // LED verde apagado


    struct repeating_timer timer;
   
    
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
       
    
    

    while (1) {
        // Imprime uma mensagem a cada segundo
        printf("Tempo: %d segundos | ", counter);

        // Verifica qual LED está aceso e imprime a mensagem correspondente
        if (gpio_get(RED_LED)) {
            printf("LED Vermelho aceso\n");
        } else if (gpio_get(YELLOW_LED)) {
            printf("LED Amarelo aceso\n");
        } else if (gpio_get(GREEN_LED)) {
            printf("LED Verde aceso\n");
        }

        counter++; // Incrementa o contador de tempo
        sleep_ms(1000); // Espera 1 segundo
    }
}