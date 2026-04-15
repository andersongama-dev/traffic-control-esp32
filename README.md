---

# Traffic Control ESP32 (Arduino)

Simulação de um sistema de semáforo com controle de travessia de pedestres utilizando ESP32 no Wokwi, desenvolvido com base no framework Arduino.

## Visão Geral

Este projeto implementa um semáforo simples com três estados:

* Verde: fluxo de veículos liberado
* Amarelo: estado de transição
* Vermelho: parada obrigatória

Um botão permite que pedestres solicitem a travessia. Quando pressionado, o sistema prolonga o tempo do sinal vermelho.

---

## Funcionalidades

* Controle de LEDs (vermelho, amarelo e verde)
* Leitura de botão com `INPUT_PULLUP`
* Detecção de borda de descida (HIGH → LOW)
* Solicitação de pedestre armazenada em variável (`padRequest`)
* Monitoramento contínuo do botão durante delays
* Saída de debug via `Serial`

---

## Hardware Utilizado

* ESP32 DevKit (Wokwi)
* 3 LEDs:

  * Vermelho
  * Amarelo
  * Verde
* 3 resistores (1kΩ)
* 1 botão (pushbutton)

---

## Mapeamento de Pinos

| Componente     | GPIO |
| -------------- | ---- |
| LED Vermelho   | 2    |
| LED Amarelo    | 4    |
| LED Verde      | 5    |
| Botão Pedestre | 18   |

---

## Lógica do Sistema

O sistema executa continuamente:

1. LED Verde ligado por 5 segundos
2. LED Amarelo por 2 segundos
3. LED Vermelho:

   * 5 segundos (normal)
   * 10 segundos (se botão pressionado)

Durante os tempos de espera, o botão é verificado a cada 50ms, garantindo resposta mesmo durante delays.

---

## Estrutura do Código

Funções principais do código original:

* `setup()`
  Configura os pinos e inicializa a comunicação serial

* `loop()`
  Executa continuamente o ciclo do semáforo

* `led()`
  Controla a sequência dos LEDs

* `checkButton()`
  Detecta pressionamento do botão

* `waitWithCheck(time)`
  Implementa delay com verificação do botão

---

## Código Base

O projeto foi desenvolvido utilizando funções padrão do Arduino:

* `pinMode()`
* `digitalWrite()`
* `digitalRead()`
* `delay()`
* `Serial.begin()`
* `Serial.println()`

---

## Simulação no Wokwi

Acesse o circuito completo no link abaixo:

👉 **[Abrir simulação no Wokwi](https://wokwi.com/projects/461333441226454017)**

---

## Como Executar

1. Abra o link do Wokwi
2. Clique em **Start Simulation**
3. Pressione o botão para simular solicitação de pedestre
4. Observe o comportamento do semáforo e logs no Serial Monitor

---

## Observações Técnicas

* O botão utiliza `INPUT_PULLUP`, portanto:

  * Não pressionado = HIGH
  * Pressionado = LOW

* A detecção de clique ocorre na transição:

```cpp
if (previousState == HIGH && currentStatus == LOW)
```

* Não há debounce avançado (apenas mitigado pelo intervalo de 50ms)

---
