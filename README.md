# Temporizador de um disparo (One Shot)

O projeto foi desenvolvido no contexto da **Unidade 4 do Capítulo 4 do EmbarcaTech (TIC37)**, Programa de Residência Tecnológica.

## Descrição
Este projeto implementa um software que em conjunto com a placa de desenvolvimento BitDogLab faz com que 3 leds sejam acionados 
e desligados individualmente através de um sistema de estados, simulando, assim, um sistema de alarme.

## Funcionalidades
- Controle automatizado do tempo de sinalização.
- Indicação visual através de LEDs.
- Ajuste dinâmico de tempos de espera.
- Implementação de rotinas de alarme 

### Objetivos do Projeto

- Mudar estado dos LEDs para ligado e desligado através da função `call-back`.

---

## Como Clonar e Testar o Código

### Pré-Requisitos

- **Raspberry Pi Pico W 2040** (ou equivalente)
- **VSCode** com extensões para desenvolvimento com a Raspberry Pi Pico
  - **C/C++ Extension** (para suporte a C e C++)
  - **Pico SDK** configurados
  - **Wokwi** (opcional para simulação online do código)

### Dependências

1. **Pico SDK**: Para compilar o código C para a Raspberry Pi Pico W2040.

2. **Bibliotecas de Hardware**:
   - `pico/stdlib.h`: Para funções padrão.
   - `hardware/gpio.h`: Controle dos pinos de entrada e saída
   - `hardware/timer.h`: Gerenciamento de temporizadores


### Passo a Passo para Clonar e Rodar o Código

1. **Clonar o Repositório**:
   Abra o terminal e clone o repositório com o seguinte comando:

   ```bash
   git clone https://github.com/IkaroJS/Tarefa_oneShot.git
   cd Tarefa_oneShot

2. **Compilar e Rodar o Código**:
   - Abra o arquivo `Tarefa_oneShot.c` no VSCode.
   - Configure o ambiente de desenvolvimento para a Raspberry Pi Pico W usando o Pico SDK.
   - Compile o código C para a Raspberry Pi Pico W.
   - Execute o código C no Pico W.
   - O código será compilado e enviado para o Pico W.

### Autor

- **Ikaro Jesus da Silva**