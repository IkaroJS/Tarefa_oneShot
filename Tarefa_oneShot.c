#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_BLUE 11
#define LED_RED 12
#define LED_GREEN 13
#define BUTTON 5
#define DELAY_MS 3000

// Variável para controlar se a sequência de LEDs está em execução
volatile bool sequence_running = false;

// Função para inicializar os pinos GPIO dos LEDs e do botão
void init_pins() {
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, false);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, false);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, false);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
}

// Função chamada periodicamente para desligar os LEDs em sequência
bool led_sequence_callback(struct repeating_timer *t) {
    static int step = 0;
    switch (step) {
        case 0:
            gpio_put(LED_BLUE, 0);
            break;
        case 1:
            gpio_put(LED_RED, 0);
            break;
        case 2:
            gpio_put(LED_GREEN, 0);
            sequence_running = false;
            return false; // Para a repetição
    }
    step++;
    return true;
}

// Função para iniciar a sequência de LEDs apenas se nenhuma estiver em andamento
void start_led_sequence() {
    if (sequence_running) return;
    sequence_running = true;
    gpio_put(LED_BLUE, 1);
    gpio_put(LED_RED, 1);
    gpio_put(LED_GREEN, 1);
    
    static struct repeating_timer timer;
    add_repeating_timer_ms(-DELAY_MS, led_sequence_callback, NULL, &timer);
}

// Função para implementar debounce por software e evitar múltiplos acionamentos
bool debounce_button() {
    static uint32_t last_press_time = 0;
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (current_time - last_press_time < 200) return false;
    last_press_time = current_time;
    return true;
}

// Função acionada por interrupção ao pressionar o botão, iniciando a sequência de LEDs
void button_callback(uint gpio, uint32_t events) {
    if (!sequence_running && debounce_button()) {
        start_led_sequence();
    }
}

int main() {
    stdio_init_all();
    init_pins();
    
    // Configura a interrupção do botão
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);
    
    // Loop principal que mantém o programa rodando
    while (1) {
        tight_loop_contents();
    }
}
